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
	std::clog << "GameLogic::~GameLogic()\n";
	_instanceFlag = false;
}


void GameLogic::start()
{


	std::clog << "GameLogic::GameLogic()\n";
	_renderer = graphics::Renderer::get();
	_pEngine = physics::PhysicsEngine::get();
	_wController = window::Window::get();
	_wController->open();

    _player = new Player(Vector3f(0.0f, 0.8f, 0.0f));


    _iController = gamein::InputController::get();

    _enemies.push_back(new ::physics::Enemy(Vector3f(0.0f, 0.5f, 0.0f)));

    _renderer->registerGraphics(_enemies[0]);


	glShadeModel(GL_SMOOTH);
    float light_position[] = {0.0f, 20.0f, 0.0f, 1.0f};
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
	// glEnable(GL_COLOR_MATERIAL);
	glClearColor(0,.5,.5,1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640/480.0,1,500.0);

	glMatrixMode(GL_MODELVIEW);

 std::clog << "GameLogic::GameLogic()\n";
}

void GameLogic::update()
{
	// Handles Check for Collision and other functions that need to be updated
    _enemies[0]->patrol(_player->getCamera()->getLocation());
};


void GameLogic::run()
{
	std::clog << "GameLogic::start()\n";
	float angle =0.0;
	const int FPS = 30;
	Uint32 start;
	bool running = true;
	while(running)
	{
		start = SDL_GetTicks();
		running = _iController->HandleInput(_player->getCamera(),running);

        //handle logic and rendering below
	    std::clog << "GameLogic::start()->update();\n";
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
	}
	std::clog << "GameLogic::start()\n";
}


void GameLogic::show()
{std::clog << "GameLogic::show()\n";
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	_player->getCamera()->control();
    _player->getCamera()->update();

 _renderer->drawDynamic();   //CAUSES A GRAPHICS GLITCH UNCOMMENT AND SEE
	_renderer->drawStatic();

 std::clog << "GameLogic::show()\n";
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

