#include "LevelFactory.h"
namespace level{


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
 if(levelType == "Text"){
  return new TextLevel;
 }
 if(levelType == "Flat"){
  return new FlatLevel;
 }
 if(levelType == "Random"){
  return new RandomLevel;
 }

}











}//namespace level
