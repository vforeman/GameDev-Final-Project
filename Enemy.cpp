#include "src/Enemy.h"
namespace physics{


Enemy::Enemy() : _health(100), _alive(true)
{
    
}

void Enemy::attack()
{

}

void Enemy::createSimplePatrol()
{
 unsigned int range = util::xorshift()%256;
 unsigned int rangeZ = util::xorshift()%256;
 Vector3f pos = _position;
 for(unsigned int i = 0; i < range; ++i)
 {
    pos.x += 0.25f;
    _patrolPath.push_back(pos);
 }
 for(unsigned int i = 0; i < rangeZ; ++i)
 {
    pos.z += 0.25f;
    _patrolPath.push_back(pos);
 }
 for(unsigned int i = 0; i < range; ++i)
 {
    pos.x -= 0.25f;
    _patrolPath.push_back(pos);
 }
 for(unsigned int i = 0; i < rangeZ; ++i)
 {
      pos.z -= 0.25f;
      _patrolPath.push_back(pos);
 }

}

void Enemy::die()
{
    _alive = false;
}

void Enemy::patrol()
{
}

void Enemy::target()
{
}

}//namespace physics
