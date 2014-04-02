#include "PhysicsEngine.h"
namespace physics{

void PhysicsEntity::update()
{

};

bool PhysicsEngine::_instanceFlag = false;
PhysicsEngine * PhysicsEngine::_instance = NULL:

PhysicsEngine::PhysicsEngine()
{
	//empty constructor
}

PhysicsEngine::~PhysicsEngine()
{
	_instanceFlag = false;
}

PhysicsEngine * PhysicsEngine:getInstance()
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

bool PhysicsEngine::checkSphereSphere( PhysicsEntity, PhysicsEntity )
{

}
bool PhysicsEngine::checkPlaneSphere( PhysicsEntity, Level )
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


}//namespace physics
