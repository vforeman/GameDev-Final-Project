#include "src/Enemy.h"
namespace physics{


Enemy::Enemy() : _health(100),  _alive(true), _point(0),
                 _alert(false), _ALERT_RADIUS(20.0f)
{
    initialize("Circle");    
    createSimplePatrol();
}

Enemy::Enemy(Vector3f pos) : _health(100), _alive(true), _point(0),
                             _alert(false), _ALERT_RADIUS(20.0f)
{
    _position = pos;
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
    
    /*
    for(unsigned int i = 0; i < range; ++i)
    {
        pos.x += 0.5f;
        _patrolPath.push_back(pos);
    }
    for(unsigned int i = 0; i < rangeZ; ++i)
    {
        pos.z += 0.5f;
        _patrolPath.push_back(pos);
    }
    for(unsigned int i = 0; i < range; ++i)
    {
        pos.x -= 0.5f;
        _patrolPath.push_back(pos);
    }
    for(unsigned int i = 0; i < rangeZ; ++i)
    {
        pos.z -= 0.5f;
        _patrolPath.push_back(pos);
    }  
    */
    pos.x += 10.0f;
    _patrolPath.push_back(pos);
    pos.z += 10.0f;
    _patrolPath.push_back(pos);
    pos.x -= 10.0f;
    _patrolPath.push_back(pos);
    pos.z -= 10.0f;
    _patrolPath.push_back(pos);
}

void Enemy::die()
{
    _alive = false;
}

void Enemy::patrol(Vector3f target)
{
    if(physics::PhysicsEngine::spheresphere(_position, _ALERT_RADIUS, target, 0.5f) )
    {
        //Fire at player
        printf("MUST DESTROY!!!\n");
    }
    else
    {
        if(!(_position.x - _patrolPath[_point].x < 0.25f && _position.x - _patrolPath[_point].x > -0.25f &&
            _position.y - _patrolPath[_point].y < 0.25f && _position.y - _patrolPath[_point].y > - 0.25f &&
            _position.z - _patrolPath[_point].z < 0.25f && _position.z - _patrolPath[_point].z > -0.25f  ))
        {
            Vector3f trans = _patrolPath[_point] - _position;
            trans.normalize();
            _position = _position + trans*0.125f;
        } 
        else
        {
            ++_point;
            if(_point >= _patrolPath.size())
                _point = 0;
        }
    }
}

void Enemy::target()
{
}

}//namespace physics
