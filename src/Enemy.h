#ifndef ENEMY_H
#define ENEMY_H
#include "PhysicsEngine.h"
#include "Vmath.h"
#include <vector>
#include "Util.h"
namespace physics{

class Enemy : public PhysicsEntity
{
public:
 Enemy();
 bool _alive;
 int _health;
 void attack();
 void die();
 void patrol();
private:
 std::vector< Vector3f > patrolPath;
 void createSimplePatrol();
 void target();
};
}//namespace physics
#endif// ENEMY_H
