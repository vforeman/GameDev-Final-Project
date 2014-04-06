#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "LevelFactory.h"
#include "Geometry.h"
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
class Bullet : public PhysicsEntity
{
public:
 Bullet();
 std::string _type;
};

/***********************************
*					PLAYER SPECIFICATION
*************************************/
class Player : PhysicsEntity{

};

/***********************************
*						QUADTREE SPECIFICATION
*************************************/
class QuadTree
{
public:
	QuadTree();
	QuadTree( int, geo::Rectangle);
	~QuadTree();
	void setQuadConsts(int , int );
private:
	//maximum objects the quadtree can hold
	static const int MAX_OBJECTS;
	//indicates the lowest degree in quadtee
	static const int MAX_DEGREES;
	//degree of current quadtree
	int _degree;
	//dynamic array of objs in current quadtree
 PhysicsEntity * _objs;
	//bounding rect of quadtree area
	geo::Rectangle _bound;
	//qtree pointer to dynamic array of qtrees
	QuadTree *_nodes;
};

/***********************************
*					PHYSICS ENGINE SPECIFICATION
*************************************/
class PhysicsEngine
{
public:
	static PhysicsEngine * getInstance();
	~PhysicsEngine();
/*	bool checkSphereSphere( PhysicsEntity, PhysicsEntity );
	bool checkPlaneSphere( PhysicsEntity, level::LevelFactory );
	void resolvePlayerEnemy( Player , Enemy );
	void resolvePlayerBullet(Player , Bullet );
	void resolveBulletEnemy( Enemy, Bullet );*/


private:
	static PhysicsEngine * _instance;
	static bool _instanceFlag;
	PhysicsEngine();
};














}//namespace physics
#endif
