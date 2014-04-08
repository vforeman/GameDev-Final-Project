#include "WindowController.h"
namespace window{

bool Window::_instanceFlag = false;
Window * Window::_instance = NULL;
SDL_Surface * Window::_screen = NULL;

Window::Window(){}

Window::~Window()
{
 _instanceFlag = false;
}

Window * Window::get()
{
 if(_instance == NULL)
 {
  _instance = new Window();
  _instanceFlag = true;
  return _instance;
 }
 else
 {
  return _instance;
 }
}

void Window::open()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	_screen = SDL_SetVideoMode(1280,960,32,SDL_SWSURFACE|SDL_OPENGL);
}

void Window::close(){}
/*
void Window::resize( int width, int height){}

void Window::resize( char * ch){}*/

}//namespace window
