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

  //glDisable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA/*_SATURATE*/, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_COLOR_MATERIAL);

  // glDisable(GL_LIGHTING);

  //loaded with cube data right now
  //Enable vertex arrays we want to draw with
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_INDEX_ARRAY);

  if(_firstDraw){
    _firstDraw=true;
    //Connect the arrays themselves
    glVertexPointer(3, GL_FLOAT, 0, &_lvl._staticVertices[0]);
    glIndexPointer(GL_INT,0,&_lvl._staticIndex[0]);
    glNormalPointer(GL_FLOAT, 0, &_lvl._staticNormals[0]);
    glColorPointer(4, GL_FLOAT, 0, &_lvl._staticColors[0]);
  }
  //removed encapsulating stack moves, hopeful speedup
  glDrawArrays(GL_QUADS , 0,_lvl._staticVertices.size()/3);

  //TODO::I dont think I should be loading the vertex data every call
  //Disable vertex arrays that are no longer in use
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_INDEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
  // glEnable(GL_LIGHTING);
  glDisable(GL_COLOR_MATERIAL);
  // drawHud();

}
void Renderer::drawDynamic()
{ glColor3f(1,0,0);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA/*_SATURATE*/, GL_SRC_ALPHA);
  glEnable(GL_COLOR_MATERIAL);
    for(unsigned int i = 0; i < _drawObjects.size(); ++i)
    {
        try
        {
            ::physics::Enemy* e = dynamic_cast< ::physics::Enemy* >( _drawObjects[i] );

	            glMatrixMode(GL_MODELVIEW);
                glPushMatrix();
                cout<<e->_verts.size();
                cout<<e->_norms.size();
                glTranslatef(e->_position.x, e->_position.y, e->_position.z);
                // e->drawSphere();
                glEnableClientState(GL_VERTEX_ARRAY);
                glEnableClientState(GL_NORMAL_ARRAY);
                // glEnableClientState(GL_INDEX_ARRAY);
                    //Connect the arrays themselves
                glVertexPointer(3, GL_FLOAT, 0, &e->_verts[0]);
                // glIndexPointer(GL_INT,0,&_lvl._staticIndex[0]);
                glNormalPointer(GL_FLOAT, 0, &e->_norms[0]);
                // glColorPointer(4, GL_FLOAT, 0, &_lvl._staticColors[0]);

                //removed encapsulating stack moves, hopeful speedup
                glDrawArrays(GL_TRIANGLE_STRIP , 0,e->_verts.size()/3);

                //TODO::I dont think I should be loading the vertex data every call
                //Disable vertex arrays that are no longer in use
                glDisableClientState(GL_VERTEX_ARRAY);
                // glDisableClientState(GL_INDEX_ARRAY);
                glDisableClientState(GL_NORMAL_ARRAY);
                // glDisableClientState(GL_COLOR_ARRAY);
                glPopMatrix();

        }
        catch(exception e)
        {
            printf("Exception: %s\n", e.what());
        }
    }
}

void Renderer::registerGraphics(Graphics* g)
{
    //Register graphics Objects with dynamic draw array
    _drawObjects.push_back(g);
}

void Renderer::emptyObjects()
{
    //If all enemies are defeated empty draw container
    //Will clear the graphics array
    //Might be good with end cleanup of game
    _drawObjects.clear();
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

void Renderer::drawHud(){

  int playerbullets = 10;
  glMatrixMode(GL_PROJECTION);

  glPushMatrix();
  glLoadIdentity();
  glOrtho(0.0, 640, 480, 0.0, -1.0, 10.0);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
  glDisable(GL_CULL_FACE);
  glClear(GL_DEPTH_BUFFER_BIT);
  glDepthMask(GL_FALSE);
  glDisable(GL_DEPTH_TEST);


  for(int k =0; k < playerbullets; ++k){

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0);
      glVertex2f(10.0, 10*k+0.0);
      glVertex2f(0.0, 10*k+0.0);
      glVertex2f(10.0, 10*k+10.0);
      glVertex2f(0.0, 10*k+10.0);
    glEnd();

  }


  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glDepthMask(GL_TRUE);
  glEnable(GL_DEPTH_TEST);

/*
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  glPushMatrix();
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0.0f, 1280, 960, 0.0f, 0.0f, 1.0f);
  glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(640, 470);
        glVertex2f(640, 490);
        glVertex2f(630, 480);
        glVertex2f(650, 480);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
*/
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


