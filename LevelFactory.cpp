#include "LevelFactory.h"
namespace level{





/***********************************
*												LEVEL IMPLEMENTATION
*************************************/
bool LevelContainer::_instanceFlag = false;
LevelContainer * LevelContainer::_instance = NULL;

LevelContainer::LevelContainer()
{
	//empty constructor
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


void Level::setType( string levelType )
{
	_type = levelType;
}

FlatLevel::FlatLevel()
{

}
void FlatLevel::draw()
{

}

TextLevel::TextLevel()
{

}
void TextLevel::draw()
{

}

RandomLevel::RandomLevel()
{

}
void RandomLevel::draw()
{

}

Level * LevelFactory::CreateLevel( string levelType)
{
 if(levelType == "Text")
 {
  return new TextLevel;
 }
 else if(levelType == "Random")
 {
  return new RandomLevel;
 }
 else /*if(levelType == "Flat")*/
 {
  return new FlatLevel;
 }
}











}//namespace level
