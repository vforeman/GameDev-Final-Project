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
*						QUADTREE IMPLEMENTATION
*************************************/
//INIT static const attributes
const int QuadTree::MAX_OBJECTS = 10;
const int QuadTree::MAX_DEGREES = 5;

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
	_objs = new PhysicsEntity[MAX_OBJECTS];
}
QuadTree::~QuadTree()
{
	delete[] _nodes;
	delete[] _objs;
}


/*class QuadTree
{
public:
	QuadTree( int, geo::Rectangle);
private:
	//maximum objects the quadtree can hold
	const int MAX_OBJECTS;
	//indicates the lowest degree in quadtee
	const int MAX_DEGREES;
	//degree of current quadtree
	int _degree;
	//dynamic array of objs in current quadtree
 PhysicsEntity * _objs;
	//bounding rect of quadtree area
	geo::Rectangle _bound;
	//qtree pointer to dynamic array of qtrees
	QuadTree *_nodes;
};*/









/***********************************
*						PHYSICS ENGINE IMPLEMENTATION
*************************************/
bool PhysicsEngine::_instanceFlag = false;
PhysicsEngine * PhysicsEngine::_instance = NULL;

PhysicsEngine::PhysicsEngine()
{
	//empty constructor
}

PhysicsEngine::~PhysicsEngine()
{
	_instanceFlag = false;
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
