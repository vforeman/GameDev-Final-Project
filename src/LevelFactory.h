#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H
#include <string>
#include "Vmath.h"
#include "Geometry.h"
using namespace std;
namespace level{



/***********************************
*												LEVEL SPECIFICATION
*************************************/

class LevelContainer{
public:
	static LevelContainer * get();
	~LevelContainer();

private:
	static LevelContainer * _instance;
	static bool _instanceFlag;
	LevelContainer();
};


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
