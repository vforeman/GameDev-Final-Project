#include "src/WindowController.h"
namespace window{

SDL_Surface * Window::_screen = NULL;

Window::Window(){}

Window& Window::get()
{
    static Window instance;
    return instance;
}

void Window::open()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	_screen = SDL_SetVideoMode(1280,960,32,SDL_SWSURFACE|SDL_OPENGL);
/*	SDL_WM_ToggleFullScreen(_screen);
*/}

void Window::close(){}
/*
void Window::resize( int width, int height){}

void Window::resize( char * ch){}*/

}//namespace window
