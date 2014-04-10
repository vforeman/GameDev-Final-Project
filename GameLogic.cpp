#include "GameLogic.h"

namespace logic
{
GameLogic * GameLogic::_instance = NULL;
bool GameLogic::_instanceFlag = false;
DATA GameLogic::_data;

GameLogic::GameLogic()
{
	GameLogic::_data._wController = window::Window::get();
	GameLogic::_data._wController->open();
	GameLogic::_data._cam = new Camera();
	GameLogic::_data._cam->setLocation(Vector3f(0,0.8,0));
	GameLogic::_data._iController = gamein::InputController::get();
	level::LevelContainer::get()->genFlat(_objs,40,40);
	GameLogic::_data._obj = new Dummy();

	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640/480.0,1,500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
};

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
		running = GameLogic::_data._iController->HandleInput(GameLogic::_data._cam,running);
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
	}
};

void GameLogic::update()
{
	// Handles Check for Collision and other functions that need to be updated
};
//TODO: use Renderer Singleton Here

void GameLogic::show()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	GameLogic::_data._cam->control();
	GameLogic::_data._cam->update();
	glTranslatef(10.0,0.0,0.0);
	GameLogic::_data._obj->drawSphere();
	GameLogic::_data._obj->drawEnvironment();
/*	level::PartitionTree::get();
*//* level::LevelContainer::get()->drawLevel();
*/
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
