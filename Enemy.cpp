#include "Enemy.h"

void Enemy::attack()
{

}

void createSimplePatrol()
{
   unsigned int range = util::xorshift()%512;
   unsigned int rangeZ = util::xorshift()%512;
   
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