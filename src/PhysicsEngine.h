#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "Geometry.h"
#include "Vmath.h"
namespace physics{

class PhysicsEntity
{
public:
 float _radius;
 Vector3f _position;
 Vector3f _velocity;
 Vector3f _force;
 void update();

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
