#include "PhysicsEngine.h"
namespace physics{

bool PhysicsEngine::_instanceFlag = false;
PhysicsEngine * PhysicsEngine::_instance = NULL;
/*extern DATA PhysicsEngine::_data;
*/
void PhysicsEntity::update(){}

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
