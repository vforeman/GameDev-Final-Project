#include "GraphicsRenderer.h"
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

void Renderer::init()
{}
void Renderer::drawStatic()
{
	glPushMatrix();

     //Enable vertex arrays we want to draw with
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  //Connect the arrays themselves
  glVertexPointer(3, GL_FLOAT, 0, tileface);
  glNormalPointer(GL_FLOAT, 0, tilenormal);
  glColorPointer(4, GL_FLOAT, 0, tilecolor);

  //Draw command - draw everything
  glDrawArrays(GL_QUADS, 0,4);

  //Disable vertex arrays that are no longer in use
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);

 glPopMatrix();

}
void Renderer::drawDynamic()
{}








}// namespace graphics

 /* glPushMatrix();

       //Enable vertex arrays we want to draw with
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    //Connect the arrays themselves
    glVertexPointer(3, GL_FLOAT, 0, faces);
    glNormalPointer(GL_FLOAT, 0, normals);
    glColorPointer(4, GL_FLOAT, 0, colors);

    //Draw command - draw everything
    glDrawArrays(GL_QUADS, 0, 6*4);


    //Disable vertex arrays that are no longer in use
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

  glPopMatrix();*/
