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

/***********************************
*      LEVEL DECORATOR IMPLEMENTATION
*************************************/
FlatLevel::FlatLevel(){}
FlatLevel::FlatLevel(string levelType)
{
 Level * _lvl =  &LevelContainer::get()->_level;
 _lvl->_area = Vector2f(8,8);
 _lvl->_maxObjects = 10;
 _lvl->_numObjects = 1;
 _lvl->_numTiles = (8*8);
 _lvl->_type = levelType;
 _lvl->_tiles = new geo::Rectangle[_lvl->_numTiles];
 _lvl->_objs = NULL;
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
void CreateLevel( string levelType)
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
}




}//namespace level
