#include "src/InputController.h"
namespace gamein{
bool InputController::_playerDead = false;
bool InputController::_respawn = false;

InputController::InputController(){}


InputController& InputController::get()
{
    static InputController instance;
    return instance;
}

bool InputController::HandleInput(Camera * cam, bool& fireSignal, bool running)
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

						case SDLK_p:if(_playerDead){break;}
							cam->mouseIn();
							SDL_ShowCursor(SDL_ENABLE);
							break;
						case SDLK_RETURN:if(_playerDead){
							_respawn = true;
						}
						default: break;
					}
					break;

				case SDL_KEYUP:
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							running = false;
							break;

						case SDLK_p:if(_playerDead){break;}
							cam-> mouseOut();
							SDL_ShowCursor(SDL_ENABLE);
                            _mouseHidden = false;
							break;
						default: break;
					}
					break;

				case SDL_MOUSEBUTTONDOWN:if(_playerDead){break;}
					if(!_mouseHidden)
                    {
                        cam->mouseIn();
					    SDL_ShowCursor(SDL_DISABLE);
                        _mouseHidden = true;
                    }
                    else
                    {
                        //wep->fire(cam->getLocation(), Vector3f(0.0f, 0.0f, 0.0f));
                        fireSignal = true;
                        //printf("Fire\n");
                    }
					break;

				default: break;
			}
		}
	return running;
}
}// namespace gamein
