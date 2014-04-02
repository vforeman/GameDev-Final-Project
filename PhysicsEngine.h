#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "LevelFactory.h"
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
	static PhysicsEngine * getInstance();
	~PhysicsEngine();
	bool checkSphereSphere( PhysicsEntity, PhysicsEntity );
	bool checkPlaneSphere( PhysicsEntity, level::LevelFactory );
	void resolvePlayerEnemy( Player , Enemy );
	void resolvePlayerBullet(Player , Bullet );
	void resolveBulletEnemy( Enemy, Bullet );


private:
	static PhysicsEngine * _instance;
	static bool _instanceFlag;
	PhysicsEngine();
};


}//namespace physics
#endif
