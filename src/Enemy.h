#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "PhysicsEngine.h"
#include "Vmath.h"
#include "Util.h"
namespace physics{
/***********************************
*                   ENEMY SPECIFICATION
*************************************/
class Enemy : public PhysicsEntity
{
public:
 Enemy();
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
