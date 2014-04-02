#include "GraphicsRenderer.h"
namespace graphics{

bool Renderer::_instanceFlag = false;
Renderer * Renderer::_instance = NULL;

Renderer::Renderer()
{
	//emptry constructor
}

Renderer::~Renderer()
{
	_instance = false;
}

Renderer * Renderer::getInstance()
{
 if(!_instanceFlag)
 {
  _instance = new Renderer();
  _instanceFlag = true;
  return _instance;
 }
 else
 {
  return _instance;
 }
}


}// namespace graphics
