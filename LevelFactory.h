#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H
#include <string>
#include "Vmath.h"
#include "Geometry.h"
using namespace std;
namespace level{
/*
USAGE:
Level * lvl;
LevelFactory * lvlFactory;
lvl=lvlFactory->createLevel("Text");


*/


/***********************************
*												LEVEL SPECIFICATION
*************************************/
class Level{
public:
 void setType( string );
 virtual void draw()=0;
private:
 string _type;

};

// Concrete Level
class FlatLevel : public Level{
private:

public:
 FlatLevel();
 ~FlatLevel();
void draw();


};

// Concrete Level
class TextLevel : public Level{
public:
 TextLevel();
 ~TextLevel();
 void draw();


};

// Concrete Level
class RandomLevel : public Level{
public:
 RandomLevel();
 ~RandomLevel();
 void draw();



};

// Factory Method for Level construction
class LevelFactory{
public:
 Level *CreateLevel( string );

};





}//end of level namespace
#endif //LEVELFACTORY_H
