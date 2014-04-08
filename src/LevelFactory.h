/**@Dependencies:
*	Geometry.h	Vmath.h	PhysicsEngine.h
**/
#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include "BSP.h"
// #include "Tiles.h"
#include "Vmath.h"
/*#include "Geometry.h"*/
#include "PhysicsEngine.h"
#include <iostream>
#include <vector>
using namespace std;
namespace level{

/**************************************************************/

// Concrete Level
class FlatLevel
{
private:
public:
 FlatLevel(string);
 FlatLevel();
void draw();
};

// Concrete Level
class TextLevel
{
public:
 TextLevel(string);
 TextLevel();
 void draw();
};

// Concrete Level
class RandomLevel
{
public:
 RandomLevel(string);
 RandomLevel();
 void draw();
};


/***********************************
*						LEVEL CONTAINER SPECIFICATION
*************************************/

typedef struct
{
	vector<float>roomlist;
 PartitionTree * _ptree;
 std::vector<Leaf*> _room;
 GLfloat * _mesh;
	string _type;
 int _numTiles;
	int _maxObjects;
	int _numObjects;
	physics::PhysicsEntity * _objs;

}DATA;

class LevelContainer{
public:
	static LevelContainer * get();
	static DATA _data;
 void drawLevel();
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
void createLevel( string );
/*void genTiles();
*/void genMesh(int , int);
void printMesh();

}//end of level namespace
#endif //LEVELFACTORY_H
