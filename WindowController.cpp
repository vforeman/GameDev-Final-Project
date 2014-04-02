#include "WindowController.h"

namespace window{

// INIT static attributes
bool Window::_instanceFlag = false;
Window * Window::_instance = NULL;

//private constructor per Signleton-Pattern
Window::Window()
{
 //empty constructor
}

///Destructor Method
Window::~Window()
{
 _instanceFlag = false; //no current instance
}

//Get CURRENT or ONLY instance
Window * Window::getInstance()
{
 if(!_instanceFlag)
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

}

void Window::close()
{

}

void Window::resize( int width, int height)
{

}

void Window::resize( char * ch)
{

}

}//namespace window
