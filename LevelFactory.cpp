#include "LevelFactory.h"
namespace level{






/***********************************
*    LEVEL IMPLEMENTATION
*************************************/
bool LevelContainer::_instanceFlag = false;
LevelContainer * LevelContainer::_instance = NULL;
Level LevelContainer::_level;
LevelContainer::LevelContainer()
{
}

LevelContainer::~LevelContainer()
{
 _instanceFlag = false;
}

LevelContainer * LevelContainer::get()
{
 if(!_instanceFlag)
 {
  _instance = new LevelContainer();
  _instanceFlag = true;
  return _instance;
 }
 else
 {
  return _instance;
 }
}
//TODO: this should really be done by the renderer
void LevelContainer::drawLevel()
{
 printf("%s\n","drawLevel()" );
 glPushMatrix();
  glColor3f(0,1,1);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, _level._mesh);
  glDrawArrays(GL_QUADS, 0, 4);
  glDisableClientState(GL_VERTEX_ARRAY);
 glPopMatrix();

 printf("%s\n","~drawLevel()" );
}

/***********************************
*      LEVEL DECORATOR IMPLEMENTATION
*************************************/
FlatLevel::FlatLevel(){}
FlatLevel::FlatLevel(string levelType)
{
 Level * lvl =  &LevelContainer::get()->_level;
 lvl->_area = Vector2f( 8 , 8 );
 lvl->_maxObjects = 10;
 lvl->_numObjects = 1;
 lvl->_numTiles = ( 8 * 8 );
 lvl->_type = levelType;
 lvl->_tiles = new geo::Rectangle[lvl->_numTiles];
 lvl->_objs = NULL;

}
FlatLevel::~FlatLevel(){}

void FlatLevel::draw()
{

}
TextLevel::TextLevel(){}
TextLevel::~TextLevel(){}
TextLevel::TextLevel(string levelType)
{
 Level * _lvl =  &LevelContainer::get()->_level;
}
void TextLevel::draw()
{

}
RandomLevel::RandomLevel(){}
RandomLevel::~RandomLevel(){}
RandomLevel::RandomLevel(string levelType)
{
 Level * _lvl =  &LevelContainer::get()->_level;
}

void RandomLevel::draw()
{

}


/***********************************
*     HELPER IMPLEMENTATION
*************************************/
void genMesh()
{
 Level * lvl = &LevelContainer::get()->_level;
 GLfloat ** mesh = lvl->_mesh;
 int numObjs = lvl->_numObjects;
 Vector2f area = lvl->_area;
 mesh = new GLfloat * [4];
 for(int n = 0; n < 4; ++n)
 {
  mesh[n] = new GLfloat[3];
 }


}
void genTiles()
{
 Level * lvl = &LevelContainer::get()->_level;
 geo::Rectangle * tiles = lvl->_tiles;
 Vector2f area = lvl->_area;
 int numTiles = lvl->_numTiles;
 for(int n = 0; n < area.x; ++n)
 {
  for(int m = 0; m < area.y; ++m)
  {
   tiles[n+m]=geo::Rectangle(n,-1,m,0);
  }
 }
}

void createLevel( string levelType)
{
 if(levelType == "Text")
 {
  TextLevel(levelType);
 }
 else if(levelType == "Random")
 {
  RandomLevel(levelType);
 }
 else /*if(levelType == "Flat")*/
 {
  FlatLevel(levelType);
 }
 genTiles();
 genMesh();
}




}//namespace level
