#include "GameLogic.h"
using namespace window;

bool GameLogic::_instanceFlag = false;
GameLogic * GameLogic::_instance = NULL;

GameLogic::GameLogic()
{
	wController = Window::getInstance();
	wController->open();
	cam.setLocation(Vector3<float>(0,0.8,0));
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640/480.0,1,500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	
	

};
GameLogic::~GameLogic()
{
	_instanceFlag = false;	
	
};


void GameLogic::start()
{
	iController = InputController::getInstance();
	float angle =0.0;
	const int FPS = 30;
	Uint32 start;
	bool running = true;
	while(running)
	{
		start = SDL_GetTicks();
		running = iController->HandleInput(cam,running);


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

void GameLogic::show()
{
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	cam.control();
	cam.update();
	glTranslatef(10.0,0.0,0.0);
	obj.drawSphere();
	obj.drawEnvironment();
	
	
};

GameLogic * GameLogic::getInstance()
{
 if(!_instanceFlag)
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
