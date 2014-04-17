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
    
    _enemies.push_back(new ::physics::Enemy(Vector3f(0.0f, 0.0f, 0.0f)));
    _renderer->registerGraphics(_enemies[0]);

	glEnable(GL_DEPTH_TEST);
	// glEnable(GL_LIGHTING);
	// glEnable(GL_LIGHT0);
	// glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);
	// glEnable(GL_CULL_FACE);
	// glCullFace(GL_FRONT);
	glClearDepth(100.0);
	glClearColor(1.0,1.0,1.0,1.0);

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
    printf("(%.2f, %.2f)\n", _enemies[0]->_position.x, _enemies[0]->_position.z);
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

	_renderer->drawStatic();
    //_renderer->drawDynamic();   //CAUSES A GRAPHICS GLITCH UNCOMMENT AND SEE
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
