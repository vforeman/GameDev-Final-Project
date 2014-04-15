#include "src/GameLogic.h"

namespace logic
{
GameLogic * GameLogic::_instance = NULL;
bool GameLogic::_instanceFlag = false;
extern DATA GameLogic::_data;

GameLogic::GameLogic()
{
	std::clog << "GameLogic::GameLogic()\n";
	_renderer = graphics::Renderer::get();
	_pEngine = physics::PhysicsEngine::get();

	_wController = window::Window::get();
	_wController->open();
	_cam = new Camera();
	_cam->setLocation(Vector3f(0,0.2,0));
	_iController = gamein::InputController::get();
	GameLogic::_data._obj = new Dummy();
	GameLogic::_data._obj->setPosition(10.0,0.0,0.0);
	glClearColor(1.0,1.0,1.0,1.0);
	glEnable( GL_TEXTURE_2D );
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
		running = _iController->HandleInput(_cam,running);
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
	// functions test collision with the player against all other spheres
	// enemposit was a test variable, a vector containing the position of all other spheres, should be replaced with the actual vector
	// containing enemy positions
	/*
	Vector3<float> cameraPos = cam.getLocation();
	int ii;
	//std::cout<< enemposit.size() <<std::endl;
	for(ii=0; ii < enemposit.size(); ii++)
	{
		//std::cout<<enemposit[ii]<<std::endl;
		if(PhysicsEngine::spheresphere(cameraPos,2.0,enemposit[ii],radvec[ii]))
		{
		//std::cout<<"collision"<<std::endl;
		cam.setLocation(Vector3<float>(cameraPos));
		break;
		}
	} */

	Vector3<float> cameraPos = _cam->getLocation();
	Vector3<float> enempos = GameLogic::_data._obj->getPosition();
	if(physics::PhysicsEngine::spheresphere(cameraPos,2.0,enempos,2.0))
		{
		std::cout<<"collision"<<std::endl;
		_cam->setLocation(Vector3<float>(cameraPos));
		} 
};
//TODO: use Renderer Singleton Here

void GameLogic::show()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	_cam->control();
	_cam->update();
	//glTranslatef(0.0,0.0,0.0);
	GameLogic::_data._obj->drawSphere();
	_renderer->drawStatic();


};

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
