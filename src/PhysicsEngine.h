/**@Dependencies:
*	Geometry.h	Vmath.h
**/
///TODO
//	add method to cosntructors of PhysicsEntity
// to add it to PhysicsEngine quadtree



#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
//#include "LevelFactory.h"
#include "Geometry.h"
#include "Graphics.h"
#include "Vmath.h"
#include <string>
namespace physics{


/***********************************
*					PHYSICS ENTITY SPECIFICATION
*************************************/
class PhysicsEntity
{
public:
    float _radius;
    Vector3f _position;
    Vector3f _velocity;
    Vector3f _force;
    void update();

};




/***********************************
*					BULLET SPECIFICATION
*************************************/
class Bullet : public PhysicsEntity, public Graphics
{
public:
 Bullet();
 std::string _type;
};

/***********************************
*					PLAYER SPECIFICATION
*************************************/
class Player : PhysicsEntity
{

};


/***********************************
*					STATIC ENTITY SPECIFICATION
*************************************/
class StaticEntity: public PhysicsEntity
{
public:
 StaticEntity();
 StaticEntity(float, Vector3f, Vector3f);
 ~StaticEntity();
private:

};

















class PhysicsEngine
{
public:
	static PhysicsEngine * get();
	~PhysicsEngine();

private:
	static PhysicsEngine * _instance;
	static bool _instanceFlag;
	PhysicsEngine();
};




}//namespace physics
#endif
