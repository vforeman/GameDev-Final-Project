/**@Dependencies:
*	Geometry.h	Vmath.h	PhysicsEngine.h
**/
#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
// #include "BSP.h"
#include "Tiles.h"
#include "Vmath.h"
/*#include "Geometry.h"*/
#include "PhysicsEngine.h"
#include <iostream>
using namespace std;
namespace level{
	/**************************************************************/
class Leaf
{
public:
	/**
	 * @brief [Overloaded Leaf Constructor]
	 * @details [long description]
	 * @return [new Leaf of size 0 or specified size]
	 */
	Leaf(int width = 0, int height = 0, int x =0, int y =0);
	~Leaf();
	bool split();
	int _width;
	int _height;
	float _x;
	int _y;
	Leaf * _left;
	Leaf * _right;
 geo::Rectangle _room;
	static const int MIN_LEAF_SIZE = 6;
	static const int MAX_LEAF_SIZE = 20;
};

/**************************************************************/

class PartitionTree
{
public:
	PartitionTree();
	void build();
	void roomify(Leaf*);
	const int MAPWIDTH = 50;
	const int MAPHEIGHT = 50;


	vector<float> *roomlist;
 vector<Leaf*> _leaves;



 Leaf * _root;
 bool _splitsLeft;

};

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
/* void drawLevel();*/
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
