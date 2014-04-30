#include "src/GameLogic.h"

namespace logic
{


GameLogic::GameLogic()
{
    //SINGLETON CONSTRUCTORS & DESTRUCTORS ARE EMPTY
}

void GameLogic::start()
{
     
	graphics::Renderer::get();
	physics::PhysicsEngine::get();
    gamein::InputController::get();
	window::Window::get();
	window::Window::get().open();
    _gameFont.init("./Assets/Test.ttf", 16);
    _menuFont.init("./Assets/GoldenEye.ttf", 20);
    _titleFont.init("./Assets/GoldenEye.ttf", 36);

    _player = new Player(Vector3f(0, 0.8f, 0)); //This is Eye coordinate
    _player->_radius = 0.5f;
    _weapon = new physics::Weapon();
    AIManager::getInstance().setPlayer(Vector3f(0.0f, 0.0f, 0.0f));

    spawnEnemies(); //Spawn enemies randomly a certain distance from player
    _score = 0;

    _active = true; //Set game to active in start
    _opposition = true;
    _running = false;

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
       

       _enemies[i]->_weapon.iterate();
       for(unsigned int j = 0; j < _enemies[i]->_weapon.getClip(); ++j)
       {

            if(_enemies[i]->_weapon.getBullet(j)->_position.y <= 0.0f || _enemies[i]->_weapon.getBullet(j)->_position.y >= 30.0f)
                _enemies[i]->_weapon.getBullet(j)->_active = false;
          
            if( _enemies[i]->_weapon.getBullet(j)->_active &&_player->isAlive() && 
                ::physics::PhysicsEngine::spheresphere(_enemies[i]->_weapon.getBullet(j)->_position, 0.5f, pos, 2.0f))
            {   
                //stop rendering the bullet
                _weapon->getBullet(j)->_active = false;
                _player->decreaseHealth();
                if(_score >= 4 && _difficulty >= 4)
                    _score -= 4;
            }

       }

       //if sphere-sphere collision for this enemy against the player
       if( ::physics::PhysicsEngine::spheresphere(pos, 0.5f, _enemies[i]->_position, _enemies[i]->_radius ))
       {  
           //halt movement
           //::physics::PhysicsEngine::resolveCollision(_player, _enemies[i]);
          
          if(_player->isAlive()) 
          {
            _player->decreaseHealth(_difficulty*10);
          }
       }
       
       for(unsigned int j = 0; j < _weapon->getClip(); ++j)
       {    //dont render bullets that hit the ground or go into the sky
            if(_weapon->getBullet(j)->_position.y <= 0.0f || _weapon->getBullet(j)->_position.y >= 30.0f)
            {
                _weapon->getBullet(j)->_active = false;
            }
            if( _weapon->getBullet(j)->_active && _enemies[i]->isLiving() &&::physics::PhysicsEngine::spheresphere(_weapon->getBullet(j)->_position, 0.5f, _enemies[i]->_position, _enemies[i]->_radius))
            {   //stop rendering the bullet
                _weapon->getBullet(j)->_active = false;
                //stop rendering the enemy
                _enemies[i]->decreaseHealth(_difficulty);
                _score += _difficulty;
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
    bool back2Menu = false;
    float angle =0.0;
	const int FPS = 30;
	Uint32 start;
    //_running = true;
    _fireSignal = false;
    while(_active)
    {
	    displayMenu();  
        _running = gamein::InputController::get().HandleInput(_player->getCamera(), _fireSignal, _running);    
        
        if(gamein::InputController::get().getExitSignal())
            _active = false;
        while(_running && _player->isAlive())
	    {
		    start = SDL_GetTicks();
            _running = gamein::InputController::get().HandleInput(_player->getCamera(), _fireSignal, _running);
            if(!_running)
            {
                back2Menu = true;
            }
            //handle logic and rendering below
	        update();
	        show();

	        SDL_GL_SwapBuffers();
	        angle+= 0.5;
	        if(angle >360)
		        angle-=360;

            // handle framemanagement
	        if(1000/FPS > SDL_GetTicks() - start)
		        SDL_Delay(1000/FPS -(SDL_GetTicks() - start) );

            _fireSignal = false;
	    }

        _player->getCamera()->mouseOut();
        SDL_ShowCursor(SDL_ENABLE);
        gamein::InputController::get().setMouseHidden(false);
        _player->restart();
        _running = false;
        spawnEnemies();
        _difficulty = 0;
        if(_score > _highscore)
        {
            _highscore = _score;
        }

        _score = 0;
        if(back2Menu)
        {
            printf("GameLogic Back2Menu\n");
            back2Menu = false;
            gamein::InputController::get().setExitSignal(false);
            _active = true;
        }
        
    }
	graphics::Renderer::get().emptyObjects();
    _enemies.clear();

    _gameFont.clean();
    _menuFont.clean();
    _titleFont.clean();
}


void GameLogic::show()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	_player->getCamera()->control();
    _player->getCamera()->update();
    Vector3f position = _player->getCamera()->getLocation();

    if(_fireSignal)
        _weapon->fire(position, _player->getCamera()->getForward(), false); 

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
                glColor3fv(BLACK);
                _weapon->getBullet(i)->drawSphere();
            glPopMatrix();
        }
    }

    float wall = (float) Overlay::OVERLAY_HEIGHT/2;
	//DRAW WALLS 
    glPushMatrix();
        glDisable(GL_LIGHTING);
        glBegin(GL_QUADS);
            glColor3fv(GRAY32);
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
        glEnable(GL_LIGHTING);
    glPopMatrix();
    //END DRAW WALLS
	graphics::Renderer::get().drawStatic();
	graphics::Renderer::get().drawDynamic();
    displayHUD();
	graphics::Renderer::get().drawHud();        //DRAW LAST CLEAR DEPTH BUFFER

}

void GameLogic::spawnEnemies()
{
    graphics::Renderer::get().emptyObjects();
    _enemies.clear();
    Vector3f pos;  //possible enemy position
    Vector3f player = AIManager::getInstance().getPlayer();
    ++_difficulty;
	for(int p = 0; p < NUMBER_OF_ENEMIES; ++p)
    {
		do{
            int xmax = ((int)Overlay::OVERLAY_WIDTH)/2;
		    int zmax = ((int)Overlay::OVERLAY_HEIGHT)/2;
		    float x = (float)util::randomRange(-xmax,xmax);
		    float z = (float)util::randomRange(-zmax,zmax);

            pos = Vector3f(x, 0.3f, z);
        } while(physics::PhysicsEngine::spheresphere(player, 25.0f, pos, 2.0f) ||  
                Overlay::isObstacle(pos));
        
        _enemies.push_back(new ::physics::Enemy(pos));
        graphics::Renderer::get().registerGraphics(_enemies.back());
	}

    _opposition = true;
}

void GameLogic::displayMenu()
{   
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -1.0f);
    
    glRasterPos2f(-0.40f, 0.35f);
    glColor3ub(0xff, 0xff, 0xff);

    glPushMatrix();
        glLoadIdentity();
        freetype::print(_titleFont, 430, 824, "GAME THE PLAYING");
        freetype::print(_menuFont, 400, 624, "CLICK THE MOUSE IN THE WINDOW TO START");
        freetype::print(_menuFont, 400, 574, "Shoot at Enemies by pressing the mouse button");
        freetype::print(_menuFont, 400, 524, "Move with WASD keys");
        freetype::print(_menuFont, 400, 474, "Go for the highscore");
        freetype::print(_menuFont, 512, 20, "I believe in you");

        if(_highscore>0)
            freetype::print(_menuFont, 430, 100, "Highscore %u", _highscore);

    glPopMatrix(); 
    
    SDL_GL_SwapBuffers();
}

void GameLogic::displayHUD()
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -1.0f);

    glColor3ub(0, 0, 0xff);

    glRasterPos2f(-0.40f, 0.35f);
    //glPrint("Active WGL Bitmap Text");

    glColor3ub(0xff, 0, 0);

    glPushMatrix();
    glLoadIdentity();
    //freetype::print(ourFont, 320, 200, "The quick brown fox jumps over the lazy dog");
    freetype::print(_gameFont, 20, 20, "Player Health: %d", _player->getHealth());
    freetype::print(_gameFont, 1024, 20, "Score: %u", _score);
    glPopMatrix();
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

