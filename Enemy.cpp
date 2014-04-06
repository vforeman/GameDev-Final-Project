#include "Enemy.h"
namespace physics{

void Enemy::attack()
{

}

void Enemy::createSimplePatrol()
{
   unsigned int range = util::xorShift()%512;
   unsigned int rangeZ = util::xorShift()%512;

   for(unsigned int i = 0; i < range; ++i)
       _position.x += 0.25f;
   for(unsigned int i = 0; i < rangeZ; ++i)
       _position.z += 0.25f;
   for(unsigned int i = 0; i < range; ++i)
       _position.x -= 0.25f;
   for(unsigned int i = 0; i < rangeZ; ++i)
       _position.z -= 0.25f;

}

void Enemy::die()
{

}

void Enemy::patrol()
{

}

void Enemy::target()
{

}
}//namespace physics
