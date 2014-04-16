#include "src/Enemy.h"
namespace physics{


Enemy::Enemy() : _health(100),  _alive(true), _point(0),
                 _alert(false), _ALERT_RADIUS(20.0f)
{
    initialize("Circle");    
    createSimplePatrol();
}

void Enemy::attack(Vector3f target)
{
    
}

void Enemy::createSimplePatrol()
{
    unsigned int range = util::xorshift()%512;
    unsigned int rangeZ = util::xorshift()%512;
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
    if(!(_position.x - _patrolPath[_point].x < 0.25f && _position.x - _patrolPath[_point].x > -0.25f &&
         _position.y - _patrolPath[_point].y < 0.25f && _position.y - _patrolPath[_point].y > - 0.25f &&
         _position.z - _patrolPath[_point].z < 0.25f && _position.z - _patrolPath[_point].z > -0.25f  ))
    {
        _position = _patrolPath[_point] - _position;
        _position.normalize();
        _position = _position * 0.25f;
    } 
    else
    {
        ++_point;
        if(_point >= _patrolPath.size())
            _point = 0;
    }
}

void Enemy::target()
{
}

}//namespace physics
