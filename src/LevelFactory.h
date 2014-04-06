#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H
#include <string>
#include "Vmath.h"
#include "Geometry.h"
#include "PhysicsEngine.h"
using namespace std;
namespace level{

typedef struct
{
	Vector2f _area;
	string _type;
	geo::Rectangle * _tiles;
	int _numTiles;
	int _maxObjects;
	int _numObjects;
	physics::PhysicsEntity * _objs;

}Level;




// Concrete Level
class FlatLevel
{
private:
public:
 FlatLevel(string);
 FlatLevel();
 ~FlatLevel();
void draw();
};

// Concrete Level
class TextLevel
{
public:
 TextLevel(string);
 TextLevel();
 ~TextLevel();
 void draw();
};

// Concrete Level
class RandomLevel
{
public:
 RandomLevel(string);
 RandomLevel();
 ~RandomLevel();
 void draw();

};


/***********************************
*						LEVEL CONTAINER SPECIFICATION
*************************************/
class LevelContainer{
public:
	static LevelContainer * get();
	static Level _level;

	~LevelContainer();
private:
	static LevelContainer * _instance;
	static bool _instanceFlag;
	LevelContainer();
};

/***********************************
*					HELPER SPECIFICATION
*************************************/
//@TODO: the helper class could be a registry of
// helper functions for any singleton class
// Factory Method for Level construction
void CreateLevel( string );




}//end of level namespace
#endif //LEVELFACTORY_H
