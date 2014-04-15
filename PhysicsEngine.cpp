#include "src/PhysicsEngine.h"
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


bool PhysicsEngine::spheresphere(Vector3<float>& c1,float _radius1,Vector3<float> c2,float _radius2)
{
	//std::cout<<c2<<std::endl;
	float dist=pointdistacesquare(c1,c2);
	std::cout<<dist<<std::endl;
	//float dist = 0.0f;
	if(dist<=(_radius1+_radius2)*(_radius1+_radius2))
	{
		std::cout<<c2<<std::endl;
		float a=sqrt(dist)-(_radius1+_radius2);
		Vector3<float> vec(c2-c1);
		vec.normalize();
		c1=c1+vec*a;
		return 1;
	}
	return 0;
}

float PhysicsEngine::pointdistacesquare(Vector3<float> p1,Vector3<float> p2)
{
	//std::cout<<p2<<std::endl;
	Vector3<float> vec(p2.x-p1.x,p2.y-p1.y,p2.z-p1.z);
	return (vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
}


}//namespace physics



