#include "InputController.h"

bool InputController::_instanceFlag = false;
InputController * InputController::_instance = NULL;

InputController::InputController()
{
	//emptry constructor
};

InputController::~InputController()
{
	_instanceFlag = false;
};

InputController * InputController::getInstance()
{
 if(!_instanceFlag)
 {
  _instance = new InputController();
  _instanceFlag = true;
  return _instance;
 }
 else
 {
  return _instance;
 }
};

bool InputController::HandleInput(Camera& cam,bool running)
{
	SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						running = false;
						break;

					
					case SDLK_p:
						cam.mouseIn();
						SDL_ShowCursor(SDL_ENABLE);
						break;

					
				}
				break;
				case SDL_KEYUP:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						running = false;
						break;

					
					case SDLK_p:
						cam.mouseOut();
						SDL_ShowCursor(SDL_ENABLE);
						break;

				}
				break;
				case SDL_MOUSEBUTTONDOWN:
					cam.mouseIn();
					SDL_ShowCursor(SDL_DISABLE);
					break;
			}
		}
	return running;
};