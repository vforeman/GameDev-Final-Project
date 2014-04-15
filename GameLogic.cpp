#include "GameLogic.h"

namespace logic
{
GameLogic * GameLogic::_instance = NULL;
bool GameLogic::_instanceFlag = false;

GameLogic::GameLogic()
{
	std::clog << "GameLogic::GameLogic()\n";
	_renderer = graphics::Renderer::get();
	_pEngine = physics::PhysicsEngine::get();
	_wController = window::Window::get();
	_wController->open();
	_cam = new Camera();
	_cam->setLocation(Vector3f(0,0.8,0));
	_iController = gamein::InputController::get();
	// GameLogic::_data._obj = new Dummy();

	// glClearDepth(100.0);
	glClearColor(1.0,1.0,1.0,1.0);
	// glEnable( GL_TEXTURE_2D );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640/480.0,1,500.0);
	glMatrixMode(GL_MODELVIEW);
		glEnable(GL_DEPTH_TEST);
 std::clog << "GameLogic::GameLogic()\n";
}

GameLogic::~GameLogic()
{
	std::clog << "GameLogic::~GameLogic()\n";
	_instanceFlag = false;
};

void GameLogic::start()
{
	std::clog << "GameLogic::start()\n";
	float angle =0.0;
	const int FPS = 30;
	Uint32 start;
	bool running = true;
	while(running)
	{
		start = SDL_GetTicks();
		running = _iController->HandleInput(_cam,running);
	//handle logic and rendering below
	std::clog << "GameLogic::start()->update();\n";
	update();
	show();
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

void GameLogic::update()
{
	// Handles Check for Collision and other functions that need to be updated
};
//TODO: use Renderer Singleton Here

void GameLogic::show()
{std::clog << "GameLogic::show()\n";
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	_cam->control();
	_cam->update();
	std::cout<<_cam->loc.x<<','<<_cam->loc.y<<','<<_cam->loc.z<<'\n';
	glTranslatef(0.0,0.0,0.0);
	// GameLogic::_data._obj->drawSphere();
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
