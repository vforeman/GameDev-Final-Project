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
	//empty constructor
}
QuadTree::QuadTree(int degree, geo::Rectangle bound)
{
	_degree = degree;
	_bound = bound;
	//qtrees are always subdivided by 4
	_nodes = new QuadTree[4];
	//allocate an array to hold max physics entities
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
const int PhysicsEngine::MAX_LVL_OBJECTS = 16;
PhysicsEngine::PhysicsEngine()
{
	_objs = new PhysicsEntity[MAX_LVL_OBJECTS];
}

PhysicsEngine::~PhysicsEngine()
{
	_instanceFlag = false;
	delete[] _objs;
}

PhysicsEngine * PhysicsEngine::getInstance()
{
	if(!_instanceFlag)
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

void PhysicsEngine::addToTree()
{
}

/*bool PhysicsEngine::checkSphereSphere( PhysicsEntity, PhysicsEntity )
{

}
bool PhysicsEngine::checkPlaneSphere( PhysicsEntity, level::LevelFactory )
{

}
void PhysicsEngine::resolvePlayerEnemy( Player , Enemy )
{

}
void PhysicsEngine::resolvePlayerBullet(Player , Bullet )
{

}
void PhysicsEngine::resolveBulletEnemy( Enemy, Bullet )
{

}
*/


}//namespace physics
