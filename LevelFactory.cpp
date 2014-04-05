#include "LevelFactory.h"
namespace level{


/***********************************
*												QUADTREE IMPLEMENTATION
*************************************/




/***********************************
*												LEVEL IMPLEMENTATION
*************************************/
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
