#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H
#include <string>
#include "Vmath.h"
#include "PhysicsEngine.h"
#include "Geometry.h"
#include "BSP.h"
namespace level{

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

typedef struct
{
	PartitionTree* _ptree;
	GLfloat * _mesh;
}DATA;

class LevelContainer
{
private:
	static LevelContainer * _instance;
	static bool _instanceFlag;
	LevelContainer();
public:
	static DATA _data;
	static LevelContainer * get();
	~LevelContainer();

};

void createLevel(std::string);

}//end of level namespace
#endif //LEVELFACTORY_H
