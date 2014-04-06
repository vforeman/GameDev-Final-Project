#include "LevelDecorator.h"
namespace level{
/***********************************
*												LEVEL IMPLEMENTATION
*************************************/
/*
* @TODO
*		use static container pattern to house composite
* level components. The container is an OBserver.
*	the object is what's being Obsesrved
*
*/
								/***********************************
								*												LEVEL COMPONENTS
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
