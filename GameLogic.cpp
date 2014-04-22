#include "src/GameLogic.h"

namespace logic
{
GameLogic * GameLogic::_instance = NULL;
bool GameLogic::_instanceFlag = false;

GameLogic::GameLogic()
{
    //SINGLETON CONSTRUCTORS & DESTRUCTORS ARE EMPTY
}

GameLogic::~GameLogic()
{
	_instanceFlag = false;
}


void GameLogic::start()
{
     SoundManager::getInstance().start("./Assets/TacticalSpace.ogg");
     
	_renderer = graphics::Renderer::get();
	_pEngine = physics::PhysicsEngine::get();
	_wController = window::Window::get();
	_wController->open();
    _player = new Player(Vector3f(0, 0.8f, 0));
    _weapon = new physics::Weapon();
	for(int p = 0; p < NUMBER_OF_ENEMIES; ++p){
		int xmax = ((int)Overlay::OVERLAY_WIDTH)/2;
		int zmax = ((int)Overlay::OVERLAY_HEIGHT)/2;
		float x = (float)util::randomRange(-xmax,xmax);
		float z = (float)util::randomRange(-zmax,zmax);
        _enemies.push_back(new ::physics::Enemy(Vector3f(x, 0.5f, z)));
        _renderer->registerGraphics(_enemies.back());
	}


    _iController = gamein::InputController::get();



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
    if(_fireSignal)
        _weapon->fire(_player->getCamera()->getLocation(), _player->getCamera()->getVector());
    // Handles Check for Collision and other functions that need to be updated
    for(unsigned int i = 0; i < _enemies.size(); ++i)
    {
        _enemies[i]->patrol(_player->getCamera()->getLocation());
    }
    /*for(unsigned int i = 0; i < _weapon->getClip(); ++i)
    {
        if(_weapon->getBullet(i)->_active)
        {
            printf("DEBUG\n");
            //_weapon->getBullet(i)->update();
        }
    }*/
	//_weapon->iterate();
    Vector3f test = _player->getCamera()->getLocation();
    //printf("(%.2f, %.2f, %.2f)\n", test.x, test.y, test.z);
};


void GameLogic::run()
{
	float angle =0.0;
	const int FPS = 30;
	Uint32 start;
	bool running = true;
    _fireSignal = false;
	while(running)
	{
		start = SDL_GetTicks();
		running = _iController->HandleInput(_player->getCamera(), _fireSignal, running);

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

    //Close Sound System on Exit
    SoundManager::getInstance().stop();
    usleep(250);
    SoundManager::getInstance().close();
    usleep(250);
    alutExit();
}


void GameLogic::show()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	_player->getCamera()->control();
    _player->getCamera()->update();

    Vector3f pos;
    float radius;
    for(unsigned int i = 0; i < _weapon->getClip(); ++i)
    {
        /*if(_weapon->getBullet(i)->active)
        {
            pos = _weapon->getBullet(i)->_position;
            radius = _weapon->getBullet(i)->_radius;
            glPushMatrix();
                glTranslatef(pos.x, pos.y, pos.z);
                glScalef(radius, radius, radius);
                _weapon->getBullet(i)->drawSphere();
            glPopMatrix();
        }*/
    }

    // Handles Check for Collision and other functions that need to be updated
	_renderer->drawStatic();
 _renderer->drawDynamic();
 _renderer->drawHud();		///MUST BE DRAWN LAST BECAUSE I CLEAR THE DEPTH BUFFER

}

GameLogic * GameLogic::get()
{
 if(_instance == NULL)
 {
  _instance = new GameLogic();
  _instanceFlag = true;
  return _instance;
 }
 else
 {
  return _instance;
 }
}

}// namesapce logic

