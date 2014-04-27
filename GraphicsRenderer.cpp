#include "src/GraphicsRenderer.h"
namespace graphics{
bool Renderer::_firstDraw = true;
GLuint Renderer::h_bullets;

Renderer::Renderer()
{
}

void Renderer::buildHudList()
{

}

void Renderer::playerDead(Vector3f p)
{
  glBegin(GL_QUADS);
  glColor4f(1.0,0.0,0.0,0.4);
         glVertex3f(0.4f+p.x , 4.0f +p.y , 0.4f+p.z);   glVertex3f(-0.4f+p.x , 4.0f +p.y , 0.4f+p.z);  glVertex3f(-0.4f+p.x , 4.0f +p.y ,-0.4f+p.z);  glVertex3f(0.4f+p.x , 4.0f +p.y ,-0.4f+p.z); //0123top
         glVertex3f(0.4f+p.x , 4.0f +p.y , 0.4f+p.z);   glVertex3f(-0.4f+p.x , 4.0f +p.y , 0.4f+p.z);  glVertex3f(-0.4f+p.x , 0.2f+p.y , 0.4f+p.z);  glVertex3f(0.4f+p.x , 0.2f+p.y , 0.4f+p.z); //0145north
         glVertex3f(0.4f+p.x , 4.0f +p.y , 0.4f+p.z);   glVertex3f(0.4f+p.x , 4.0f +p.y ,-0.4f+p.z); glVertex3f(0.4f+p.x , 0.2f+p.y ,-0.4f+p.z);  glVertex3f(0.4f+p.x , 0.2f+p.y , 0.4f+p.z); //0365east
         glVertex3f(0.4f+p.x , 4.0f +p.y ,-0.4f+p.z);   glVertex3f(-0.4f+p.x , 4.0f +p.y ,-0.4f+p.z);  glVertex3f(-0.4f+p.x , 0.2f+p.y ,-0.4f+p.z);  glVertex3f(0.4f+p.x , 0.2f+p.y ,-0.4f+p.z); //3276south
         glVertex3f(-0.4f+p.x , 4.0f +p.y ,-0.4f+p.z);   glVertex3f(-0.4f+p.x , 4.0f +p.y , 0.4f+p.z);  glVertex3f(-0.4f+p.x , 0.2f+p.y , 0.4f+p.z);  glVertex3f(-0.4f+p.x , 0.2f+p.y ,-0.4f+p.z); //2147west
         glVertex3f(0.4f+p.x , 0.2f+p.y , 0.4f+p.z);   glVertex3f(-0.4f+p.x , 0.2f+p.y , 0.4f+p.z);  glVertex3f(-0.4f+p.x , 0.2f+p.y ,-0.4f+p.z);  glVertex3f(0.4f+p.x , 0.2f+p.y ,-0.4f+p.z);//5476bot
  glEnd();
}
void Renderer::drawStatic()
{

  //glDisable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA/*_SATURATE*/, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_COLOR_MATERIAL);
  glDepthFunc(GL_LEQUAL);
  // glPolygonOffset()

  // glDisable(GL_LIGHTING);

  //loaded with cube data right now
  //Enable vertex arrays we want to draw with
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_INDEX_ARRAY);

  if(_firstDraw)
  {
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
  playerDead(Vector3f(0,0,0));
}

void Renderer::drawDynamic()
{ 
    glColor3f(1,0,0);
    glEnable(GL_BLEND);
    //we should toggle this whenever the sphere gets hit
    glBlendFunc(GL_SRC_ALPHA/*_SATURATE*/, GL_SRC_ALPHA);
    glEnable(GL_COLOR_MATERIAL);
    for(unsigned int i = 0; i < _drawObjects.size(); ++i)
    {
        try
        {
                ::physics::Enemy* e = dynamic_cast< ::physics::Enemy* >( _drawObjects[i] );
	            if(e->isLiving())
                {
                    glMatrixMode(GL_MODELVIEW);
                    glPushMatrix();
                    glTranslatef(e->_position.x, e->_position.y, e->_position.z);
                    glScalef(e->_radius, e->_radius, e->_radius);
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
                    
                    //printf("Before For Loop\n"); 
                    //Draw Bullets
                    for(unsigned int i = 0; i < e->_weapon.getClip(); ++i)
                    {
                        Vector3f pos;
                        float radius;
                        if(e->_weapon.getBullet(i)->_active)
                        {
                            pos = e->_weapon.getBullet(i)->_position;
                            radius = e->_weapon.getBullet(i)->_radius;
                            
                            glPushMatrix();
                                printf("Enemy Bullet Visible?\n");
                                glMatrixMode(GL_MODELVIEW);
                                glTranslatef(pos.x, pos.y, pos.z);
                                glScalef(radius, radius, radius);
                                e->_weapon.getBullet(i)->drawSphere();
                            glPopMatrix();
                        }
                    }
                    //printf("After For Loop\n");
                }
        }
        catch(exception e)
        {
            printf("Exception: %s\n", e.what());
        }
    }
    glDisable(GL_BLEND);
}

void Renderer::popBackGraphics()
{
    _drawObjects.pop_back();
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
void Renderer::drawHud()
{
glPushMatrix();
  inHudMode(640,480);
  glDisable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);
     glLineWidth(4);
    glBegin(GL_LINES);//bullet shell
      glColor4f(1.0f, 0.85f, 0.0, 0.6);
      glVertex3f( 320, 230,0 );//top
      glVertex3f( 320,  250,0 );//bottom
      glVertex3f( 310, 240,0 );//left
      glVertex3f( 330, 240,0 );//right
    glEnd();
  glDisable(GL_COLOR_MATERIAL);
  outHudMode();
  glPopMatrix();
}

void inHudMode(int screen_width, int screen_height)
{
  glPushAttrib(GL_ENABLE_BIT|GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_LIGHTING_BIT|GL_POLYGON_BIT|GL_VIEWPORT_BIT|GL_TRANSFORM_BIT);
  glMatrixMode(GL_PROJECTION);

  glPushMatrix();
  glLoadIdentity();
  glOrtho(0.0, screen_width, screen_height, 0.0, -1.0, 10.0);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
  glDisable(GL_CULL_FACE);

  //glClear(GL_DEPTH_BUFFER_BIT);
  glDepthMask(GL_FALSE);
  glDisable(GL_DEPTH_TEST);
}
void outHudMode()
{
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glDepthMask(GL_TRUE);
  glEnable(GL_DEPTH_TEST);
  glPopAttrib();
}

Renderer& Renderer::get()
{
    static Renderer instance;
    return instance;
}


}// namespace graphics


