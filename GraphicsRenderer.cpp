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
{std::clog << "Renderer::drawStatic()\n";

  //   if(count%3==0)
  //     cout<<'\n';
  //   ++count;
  //   cout<<f<<',';
  //   if(count==1024)break;
  // }
  // GLuint text =LoadTexture();
  // glPushMatrix();
      //loaded with cube data right now
     //Enable vertex arrays we want to draw with
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  //glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  //Connect the arrays themselves
  // glVertexPointer(3, GL_FLOAT, 0, tileface);
  cout<<_lvl._staticVertices.size()<<endl;
  glVertexPointer(3, GL_FLOAT, 0, &_lvl._staticVertices[0]);
  glNormalPointer(GL_FLOAT, 0, normals);
  glColorPointer(3, GL_FLOAT, 0, tilecolor);
    glPushMatrix();
     glDrawArrays(GL_LINES, 0,_lvl._staticVertices.size()/3);
    glPopMatrix();

  //Disable vertex arrays that are no longer in use
glDisableClientState(GL_VERTEX_ARRAY);
glDisableClientState(GL_NORMAL_ARRAY);
glDisableClientState(GL_COLOR_ARRAY);
// glPopMatrix();

}

void Renderer::drawStatic(Level l)
{}

void Renderer::drawLevel()
{
  drawStatic();
        //loaded with cube data right now
     //Enable vertex arrays we want to draw with
  glEnableClientState(GL_VERTEX_ARRAY);
  // glEnableClientState(GL_NORMAL_ARRAY);
  // glEnableClientState(GL_COLOR_ARRAY);

  //Connect the arrays themselves
  glVertexPointer(3, GL_FLOAT, 0, &_lvl._staticVertices);
  // glNormalPointer(GL_FLOAT, 0, tilenormal);
  // glColorPointer(3, GL_FLOAT, 6, checker);

  glDrawArrays(GL_QUADS, 0,_lvl._staticVertices.size());

  //draw randome pillars

  //Disable vertex arrays that are no longer in use
  glDisableClientState(GL_VERTEX_ARRAY);
  // glDisableClientState(GL_NORMAL_ARRAY);
  // glDisableClientState(GL_COLOR_ARRAY);

}

void Renderer::drawSphere()
{
 drawDynamic();
}
void Renderer::drawDynamic()
{
    glEnableClientState(GL_VERTEX_ARRAY);
  // glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  //Connect the arrays themselves
  glVertexPointer(3, GL_FLOAT, 0,&s._verts);
  // glNormalPointer(GL_FLOAT, 0, tilenormal);
  glColorPointer(3, GL_FLOAT, 6, checker);

     glDrawArrays(GL_QUADS, 0,s._verts.size());

  //draw randome pillars

  //Disable vertex arrays that are no longer in use
  glDisableClientState(GL_VERTEX_ARRAY);
  // glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
}



GLuint LoadTexture( )
{

  GLuint texture;

  int width, height;

  unsigned char * data;

  FILE * file;

  file = fopen( "tile.png", "rb" );

  if ( file == NULL ) return 0;
  width = 512;
  height = 512;
  data = (unsigned char *)malloc( width * height * 3 );
  //int size = fseek(file,);
  fread( data, width * height * 3, 1, file );
  fclose( file );

 for(int i = 0; i < width * height ; ++i)
  {
     int index = i*3;
     unsigned char B,R;
     B = data[index];
     R = data[index+2];

     data[index] = R;
     data[index+2] = B;

  }


  glGenTextures( 1, &texture );
  glBindTexture( GL_TEXTURE_2D, texture );
  glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );


  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
  gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
  free( data );

  return texture;
}

}// namespace graphics


