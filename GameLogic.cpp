#include "src/GameLogic.h"

namespace logic
{

GameLogic::GameLogic()
{
    //SINGLETON CONSTRUCTORS & DESTRUCTORS ARE EMPTY
}

void GameLogic::start()
{
     SoundManager::getInstance().start("./Assets/TacticalSpace.ogg");
     
	graphics::Renderer::get();
	physics::PhysicsEngine::get();
    gamein::InputController::get();
	window::Window::get();
	window::Window::get().open();

    _player = new Player(Vector3f(0, 0.8f, 0)); //This is Eye coordinate
    _player->_radius = 0.5f;
    _weapon = new physics::Weapon();
    AIManager::getInstance().setPlayer(Vector3f(0.0f, 0.0f, 0.0f));
	for(int p = 0; p < NUMBER_OF_ENEMIES; ++p)
    {
		int xmax = ((int)Overlay::OVERLAY_WIDTH)/2;
		int zmax = ((int)Overlay::OVERLAY_HEIGHT)/2;
		float x = (float)util::randomRange(-xmax,xmax);
		float z = (float)util::randomRange(-zmax,zmax);
        _enemies.push_back(new ::physics::Enemy(Vector3f(x, 0.5f, z)));
        graphics::Renderer::get().registerGraphics(_enemies.back());
	}



    _active = true; //Set game to active in start
    _opposition = true;

	glShadeModel(GL_SMOOTH);
    float light_position[] = {0.0f, 40.0f, 0.0f, 1.0f};
    GLfloat ambient_intensity[]={0.2,0.2,0.2,1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, YELLOW);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_intensity);
    glLightModeli(GL_LIGHT_MODEL_AMBIENT, GL_TRUE);
    glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
	glFrontFace(GL_CCW);//counter-clockwise order of verts determines front face of polygon
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT, ambient_intensity);
	// glMaterialf(GL_FRONT,GL_SHININESS,)
  



	glClearDepth(100.0);
	//Read that its good practice to put enable calls after setting attribues
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0,.5,.5,1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640/480.0,1,500.0);

	glMatrixMode(GL_MODELVIEW);

}

void GameLogic::update()
{
    // Handles Check for Collision and other functions that need to be updated
    bool enemiesAlive = false;
	_weapon->iterate();
    Vector3f pos = _player->getCamera()->getLocation();
    AIManager::getInstance().setPlayer(pos);
    //  iterate through the list of enemies
    for(unsigned int i = 0; i < _enemies.size(); ++i)
    {   
       if(!_enemies[i]->isLiving())
       {
           continue;
       }
        enemiesAlive = true;
        //  give this enemy the player's position
        _enemies[i]->patrol(_player->getCamera()->getLocation());
        //if sphere-sphere collision for this enemy against the player
       if( ::physics::PhysicsEngine::spheresphere(pos, 0.5f, _enemies[i]->_position, _enemies[i]->_radius ))
       {  //halt movement
           ::physics::PhysicsEngine::resolveCollision(_player, _enemies[i]);
          
          if(_player->isAlive()) 
          {
            _player->decreaseHealth(_difficulty);
          }
           else if(!_player->isAlive())
           {
                   gamein::InputController::_playerDead = true;;

                   if(gamein::InputController::get()._respawn)
                   {
                       restart();
                       gamein::InputController::_playerDead = false;
                       gamein::InputController::_respawn = false;
                   }

           }

       }
       
       for(unsigned int j = 0; j < _weapon->getClip(); ++j)
       {    //dont render bullets that hit the ground or go into the sky
            if(_weapon->getBullet(j)->_position.y <= 0.0f || _weapon->getBullet(j)->_position.y >= 30.0f)
                _weapon->getBullet(j)->_active = false;
              //if an enemy is hit
            if( _weapon->getBullet(j)->_active && _enemies[i]->isLiving() &&::physics::PhysicsEngine::spheresphere(_weapon->getBullet(j)->_position, 0.5f, _enemies[i]->_position, _enemies[i]->_radius))
            {   //stop rendering the bullet
                _weapon->getBullet(j)->_active = false;
                //stop rendering the enemy
                _enemies[i]->decreaseHealth(_difficulty);
            }
       }

    }

    _opposition = enemiesAlive;
    if(!_opposition)
    {
        printf("All enemies vanquished\n");
        spawnEnemies();        
    } 

};


void GameLogic::run()
{
	float angle =0.0;
	const int FPS = 30;
	Uint32 start;
    _running = true;
    _fireSignal = false;
	while(_running && _active)
	{
		start = SDL_GetTicks();
        _running = gamein::InputController::get().HandleInput(_player->getCamera(), _fireSignal, _running);

        //handle logic and rendering below
	    update();
	    show();

        // glDepthFunc(GL_LESS);//Would this help?
	    SDL_GL_SwapBuffers();
	    angle+= 0.5;
	    if(angle >360)
		    angle-=360;

        // handle framemanagement
	    if(1000/FPS > SDL_GetTicks() - start)
		    SDL_Delay(1000/FPS -(SDL_GetTicks() - start) );

        _fireSignal = false;
	}

	graphics::Renderer::get().emptyObjects();
    _enemies.clear();
}


void GameLogic::show()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	_player->getCamera()->control();
    _player->getCamera()->update();
    Vector3f position = _player->getCamera()->getLocation();

    if(_fireSignal)
        _weapon->fire(position, _player->getCamera()->getForward()); 

    Vector3f pos;
    float radius;
    for(unsigned int i = 0; i < _weapon->getClip(); ++i)
    {
        if(_weapon->getBullet(i)->_active)
        {
            pos = _weapon->getBullet(i)->_position;
            radius = _weapon->getBullet(i)->_radius;
            glPushMatrix();

                glMatrixMode(GL_MODELVIEW);
                glTranslatef(pos.x, pos.y, pos.z);
                glScalef(radius, radius, radius);
                _weapon->getBullet(i)->drawSphere();
            glPopMatrix();
        }
    }

    float wall = (float) Overlay::OVERLAY_HEIGHT/2;
	//DRAW WALLS 
    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3fv(SKYBLUE);
            //North Wall
            glVertex3f(-wall, -3.0f, -wall);
            glVertex3f( wall, -3.0f, -wall);
            glVertex3f( wall, 100.0f, -wall);
            glVertex3f(-wall, 100.0f, -wall);
            glNormal3d(0, 0, 1);

            //East Wall
            glVertex3f(wall, -3.0f, wall);
            glVertex3f(wall, -3.0f, -wall);
            glVertex3f(wall, 100.0f, -wall);
            glVertex3f(wall, 100.0f, wall);
            glNormal3d(0, 0, 1);

            //West Wall
            glVertex3f(-wall, -3.0f, -wall);
            glVertex3f(-wall, -3.0f, wall);
            glVertex3f(-wall, 100.0f, wall);
            glVertex3f(-wall, 100.0f, -wall);
            glNormal3d(0, 0, 1);

            //South Wall
            glVertex3f(wall, -3.0f, wall);
            glVertex3f(-wall, -3.0f, wall);
            glVertex3f(-wall, 100.0f, wall);
            glVertex3f(wall, 100.0f, wall);
            glNormal3d(0, 0, 1);
        glEnd();
    glPopMatrix();
    //END DRAW WALLS
	graphics::Renderer::get().drawStatic();
	graphics::Renderer::get().drawDynamic();
	graphics::Renderer::get().drawHud();        //DRAW LAST CLEAR DEPTH BUFFER

}

void GameLogic::spawnEnemies()
{
    graphics::Renderer::get().emptyObjects();
    _enemies.clear();

    ++_difficulty;
	for(int p = 0; p < NUMBER_OF_ENEMIES; ++p)
    {
		int xmax = ((int)Overlay::OVERLAY_WIDTH)/2;
		int zmax = ((int)Overlay::OVERLAY_HEIGHT)/2;
		float x = (float)util::randomRange(-xmax,xmax);
		float z = (float)util::randomRange(-zmax,zmax);
        _enemies.push_back(new ::physics::Enemy(Vector3f(x, 0.5f, z)));
        graphics::Renderer::get().registerGraphics(_enemies.back());
	}

}   

void GameLogic::restart()
{
    _player->restart();
    spawnEnemies();
    gamein::InputController::get()._playerDead = false;
}

GameLogic& GameLogic::get()
{
    static GameLogic instance;
    return instance;
}

}// namesapce logic

