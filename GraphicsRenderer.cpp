#include "GraphicsRenderer.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "Vmath.h"
namespace graphics{

bool Renderer::_instanceFlag = false;
Renderer * Renderer::_instance = NULL;

Renderer::Renderer(){}

Renderer::~Renderer()
{
	_instanceFlag = false;
}

Renderer * Renderer::get()
{
 if(_instance == NULL)
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
