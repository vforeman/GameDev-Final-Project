/**@Dependencies:
*	Geometry.h	Vmath.h	PhysicsEngine.h
**/
#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <vector>
#include "BSP.h"
#include "Vmath.h"
#include "Geometry.h"
#include "PhysicsEngine.h"
#include <iostream>
using namespace std;
namespace level{

typedef struct
{
	string name;
	vector<float> v;//mapmesh
}LevelContainer;

class LevelFactory
{
public:
	static LevelFactory * get();
	~LevelFactory();
	LevelContainer * getLevel(string);
private:
	LevelFactory();
	static bool _instanceFlag;
 static LevelFactory * _instance;
 static LevelContainer _levelContainer;
};


}//end of level namespace
#endif //LEVELFACTORY_H
