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

bool InputController::getExitSignal()
{
    return _exitSignal;
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
                            _exitSignal = true;
							break;

						case SDLK_p:
							cam->mouseIn();
							SDL_ShowCursor(SDL_ENABLE);
							break;
						case SDLK_RETURN:
				            break;		
						default: break;
					}
					break;

				case SDL_KEYUP:
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							running = false;
                            _exitSignal = true;
							break;

						case SDLK_p:
							cam-> mouseOut();
							SDL_ShowCursor(SDL_ENABLE);
                            _mouseHidden = false;
							break;
						default: break;
					}
					break;

				case SDL_MOUSEBUTTONDOWN:
					if(!_mouseHidden)
                    {
                        cam->mouseIn();
					    SDL_ShowCursor(SDL_DISABLE);
                        _mouseHidden = true;
                        running = true;
                    }
                    else
                    {
                        fireSignal = true;
                    }
					break;

				default: break;
			}
		}
	return running;
}

void InputController::setExitSignal(bool exitSignal)
{
    _exitSignal = exitSignal;
}

void InputController::setMouseHidden(bool hidden)
{
    _mouseHidden = hidden;
}
}// namespace gamein
