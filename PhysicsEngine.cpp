#include "PhysicsEngine.h"
namespace physics{

/***********************************
*						PHYSICS ENTITY IMPLEMENTATION
*************************************/

void PhysicsEntity::update()
{

};


/***********************************
*					ENEMY IMPLEMENTATION
*************************************/

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





/***********************************
*						QUADTREE IMPLEMENTATION
*************************************/
//INIT static const attributes
const int QuadTree::MAX_QT_OBJECTS = 10;
const int QuadTree::MAX_QT_DEGREES = 5;

QuadTree::QuadTree()
{
	QuadTree(1,geo::Rectangle(0,-1,0,0));
}
QuadTree::QuadTree(int degree, geo::Rectangle bound)
{
	_degree = degree;
	_bound = bound;
	_nodes = new QuadTree[4];
	_objs = new PhysicsEntity[MAX_QT_OBJECTS];
}
QuadTree::~QuadTree()
{
	delete[] _nodes;
	delete[] _objs;
}




/***********************************
*						PHYSICS ENGINE IMPLEMENTATION
*************************************/
bool PhysicsEngine::_instanceFlag = false;
PhysicsEngine * PhysicsEngine::_instance = NULL;
extern DATA PhysicsEngine::_data;

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

void PhysicsEngine::addToTree(){}



}//namespace physics
