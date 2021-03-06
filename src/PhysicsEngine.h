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
#include "Vmath.h"
#include "Graphics.h"
#include <string>
#include <vector>
namespace physics{


/***********************************
*					PHYSICS ENTITY SPECIFICATION
*************************************/
class PhysicsEntity
{
public:
    float _radius;
    Vector3f _position;
    Vector3f _lastPosition;
    Vector3f _trail;
    Vector3f _velocity;

    Vector3f _force;
    virtual void update();
protected:
    PhysicsEntity();
    PhysicsEntity(Vector3f);    //Initialize position
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
	static PhysicsEngine& get();
	static bool spheresphere(Vector3<float>& c1,float _radius1,Vector3<float>& c2,float _radius2);
	static float pointdistacesquare(Vector3<float> p1,Vector3<float> p2);
    static void resolveCollision(PhysicsEntity*, PhysicsEntity*); //Sphere-Sphere Collision Resolution
    static void resolveCollisionWall(PhysicsEntity * );
private:
	PhysicsEngine();
    PhysicsEngine(const PhysicsEngine&);
    PhysicsEngine& operator=(const PhysicsEngine&);
};




}//namespace physics
#endif
