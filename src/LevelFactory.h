/**@Dependencies:
*	Geometry.h	Vmath.h	PhysicsEngine.h
**/
#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include "Vmath.h"
#include "Geometry.h"
#include "PhysicsEngine.h"
#include <array>
#include <iostream>
using namespace std;
namespace level{

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
	Vector2f * _area;
	string _type;
	geo::Rectangle ** _tiles;
	int _numTiles;
	int _maxObjects;
	int _numObjects;
	physics::PhysicsEntity * _objs;
 GLfloat * _mesh;
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
void genTiles();
void genMesh(int , int);
void printMesh();

}//end of level namespace
#endif //LEVELFACTORY_H
