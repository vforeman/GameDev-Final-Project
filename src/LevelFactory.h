#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H
#include <string>
#include "Vmath.h"
#include "PhysicsEngine.h"
#include "Geometry.h"
#include "BSP.h"
#include "Util.h"
namespace level{

typedef struct
{
	float * _mesh;
}MODEL;

class FlatLevel
{
public:
	FlatLevel();
 FlatLevel(std::string);
 ~FlatLevel();
 void draw();
};

class TextLevel
{
public:
	TextLevel();
 TextLevel(std::string);
 ~TextLevel();
 void draw();
};

class RandomLevel
{
public:
	RandomLevel();
 RandomLevel(std::string);
 ~RandomLevel();
 void draw();
};



class LevelContainer
{
private:
	static LevelContainer * _instance;
	static bool _instanceFlag;
	LevelContainer();
public:
 static const float map[20][20];
	void genFlat();
	static LevelContainer * get();
	~LevelContainer();

};



}//end of level namespace
#endif //LEVELFACTORY_H
