#include "src/PhysicsEngine.h"

namespace physics{

/***********************************
*						PHYSICS ENTITY IMPLEMENTATION
*************************************/

PhysicsEntity::PhysicsEntity() : _position(Vector3f(0.0f, 0.0f, 0.0f)),
                                 _velocity(Vector3f(0.0f, 0.0f, 0.0f))
{
}

PhysicsEntity::PhysicsEntity(Vector3f pos) : _position(pos),
                                             _velocity(Vector3f(0.0f, 0.0f, 0.0f))
{
}

void PhysicsEntity::update()
{
    //x  = x0 + velocity * time
    _position = _position+ _velocity * 1.0f;
};




/***********************************
*					BULLET IMPLEMENTATION
*************************************/
Bullet::Bullet()
{
    _type = "";
}

Bullet::Bullet(Vector3f pos) 
{
    _type = "";
    _position = pos;
}
/***********************************
*					PLAYER IMPLEMENTATION
*************************************/




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




}//namespace physics



