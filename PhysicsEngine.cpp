#include "src/PhysicsEngine.h"

namespace physics{

/***********************************
*						PHYSICS ENTITY IMPLEMENTATION
*************************************/

PhysicsEntity::PhysicsEntity() 
: _position(Vector3f(0.0f, 0.0f, 0.0f)),_velocity(Vector3f(0.0f, 0.0f, 0.0f)),_force(Vector3f(0.0f, 0.0f, 0.0f))
{
}

PhysicsEntity::PhysicsEntity(Vector3f pos) 
: _position(pos), _velocity(Vector3f(0.0f, 0.0f, 0.0f)),_force(Vector3f(0.0f, 0.0f, 0.0f))
{
}

void PhysicsEntity::update()
{
    //x  = x0 + velocity * time
	    _position = _position+ _velocity * 0.25f;
}






/***********************************
*					STATIC ENTITY IMPLEMENTATION
*************************************/
StaticEntity::StaticEntity()
{

}
StaticEntity::StaticEntity(float radius, Vector3f position, Vector3f force)
{
	_radius = radius;
	_position = position;
	_velocity = Vector3f(0,0,0);
	_force = force;
}










/***********************************
*						PHYSICS ENGINE IMPLEMENTATION
*************************************/
bool PhysicsEngine::_instanceFlag = false;
PhysicsEngine * PhysicsEngine::_instance = NULL;


PhysicsEngine::PhysicsEngine(){}

PhysicsEngine::~PhysicsEngine()
{
	_instanceFlag = false;
}

PhysicsEngine * PhysicsEngine::get()
{
	if(_instance == NULL)
	{
		_instance = new PhysicsEngine();
		_instanceFlag = true;
		return _instance;
	}
	else
	{
		return _instance;
	}
}


bool PhysicsEngine::spheresphere(Vector3<float>& c1,float _radius1,Vector3<float>& c2,float _radius2)
{
	Vector3<float> temp = c1;
	if(temp.x > 10)
	temp.x / 10;
	float dist=pointdistacesquare(temp,c2);
	if(std::abs(dist)<=(_radius1+_radius2)*(_radius1+_radius2))
	{
		return 1;
	}
	return 0;
}

float PhysicsEngine::pointdistacesquare(Vector3<float> p1,Vector3<float> p2)
{
	Vector3<float> vec(p2.x-p1.x,p2.y-p1.y,p2.z-p1.z);
	return (vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
}

void PhysicsEngine::resolveCollision(PhysicsEntity* a, PhysicsEntity* b)
{	//!! b can't pass a !!
    //Resolve Collision
    //Seeking Knock back effect
    //Assume B has triple the mass of a and it will be the enemy
    a->_velocity =  (b->_velocity + b->_velocity)*2.0f;
    b->_velocity = -(b->_velocity + b->_velocity)*4.0f;
    a->update();
    b->update();
}

void PhysicsEngine::resolveCollisionWall(PhysicsEntity * b){}

}//namespace physics



