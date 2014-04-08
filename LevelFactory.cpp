#include "LevelFactory.h"
namespace level{

/***********************************
*    LEVEL IMPLEMENTATION
*************************************/
LevelContainer * LevelContainer::_instance = NULL;
bool LevelContainer::_instanceFlag = false;
extern DATA LevelContainer::_data;

LevelContainer::LevelContainer(){}

LevelContainer::~LevelContainer()
{
 _instanceFlag = false;
}

LevelContainer * LevelContainer::get()
{
 if(_instance == NULL )
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
  glVertexPointer(3, GL_FLOAT, 0, LevelContainer::_data._mesh);
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
 LevelContainer::_data._area->x = 8.0;
 LevelContainer::_data._area->y = 8.0;
 LevelContainer::_data._maxObjects = 10;
 LevelContainer::_data._numObjects = 1;
 LevelContainer::_data._numTiles = ( 8 * 8 );
 LevelContainer::_data._type = levelType;
 LevelContainer::_data._objs = new physics::PhysicsEntity[LevelContainer::_data._numObjects];
}
void FlatLevel::draw(){}

TextLevel::TextLevel(){}
TextLevel::TextLevel(string levelType)
{
 LevelContainer::_data._type = levelType;
}
void TextLevel::draw(){}

RandomLevel::RandomLevel(){}
RandomLevel::RandomLevel(string levelType)
{
 LevelContainer::_data._type = levelType;
}
void RandomLevel::draw(){}


/***********************************
*     HELPER IMPLEMENTATION
*************************************/
void genMesh(int width, int height)
{





}

void genTiles()
{
 LevelContainer::_data._tiles = new geo::Rectangle * [8];
 for(int m = 0; m < 8; ++m)
 {
  LevelContainer::_data._tiles[m] = new geo::Rectangle[8];
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
 genMesh(8,8);
}

void printMesh()
{
 for(int n = 0; n < 12; ++n){
  cout<<LevelContainer::_data._mesh[n]<<endl;
 }
}


}//namespace level
