#include "src/GraphicsRenderer.h"
namespace graphics{
bool Renderer::_firstDraw = true;
bool Renderer::_instanceFlag = false;
Renderer * Renderer::_instance = NULL;

Renderer::Renderer()
:_textureFlag(false)
{

}

Renderer::~Renderer()
{
	_instanceFlag = false;
}


void Renderer::drawStatic()
{std::clog << "Renderer::drawStatic()\n";

  glDisable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


  //loaded with cube data right now
  //Enable vertex arrays we want to draw with
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  if(_firstDraw){
    _firstDraw=false;
    //Connect the arrays themselves
    glVertexPointer(3, GL_FLOAT, 0, &_lvl._staticVertices[0]);
    glNormalPointer(GL_FLOAT, 0, &_lvl._staticNormals[0]);
    glColorPointer(4, GL_FLOAT, 0, &_lvl._staticColors[0]);
  }
  //removed encapsulating stack moves, hopeful speedup
  glDrawArrays(GL_QUADS, 0,_lvl._staticVertices.size()/3);
  //TODO::I dont think I should be loading the vertex data every call
  //Disable vertex arrays that are no longer in use
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
}

void Renderer::drawDynamic()
{

}


GLuint Renderer::loadBMP(){

  int width, height;
  unsigned char * data;
  FILE * file;
  file = fopen( "src/tile.png", "rb" );
  if ( file == NULL ){
    return 0;
  }
  width = 512;
  height = 512;
  data = (unsigned char *)malloc( width * height * 3 );
  //int size = fseek(file,);
  fread( data, width * height * 3, 1, file );
  fclose( file );
 for(int i = 0; i < width * height ; ++i){
     int index = i*3;
     unsigned char B,R;
     B = data[index];
     R = data[index+2];
     data[index] = R;
     data[index+2] = B;
  }
  glGenTextures( 1, &_texture );
  glBindTexture( GL_TEXTURE_2D, _texture );
  glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
  gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
  free( data );


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


