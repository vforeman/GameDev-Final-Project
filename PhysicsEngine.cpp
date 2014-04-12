#include "PhysicsEngine.h"
namespace physics{

/***********************************
*						PHYSICS ENTITY IMPLEMENTATION
*************************************/
void PhysicsEntity::update()
{

};




/***********************************
*					BULLET IMPLEMENTATION
*************************************/
Bullet::Bullet()
{
    _type = "";
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
StaticEntity::~StaticEntity()
{

}





Level::Level()
{}
Level::~Level()
{}
void Level::initialize()
{}



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



