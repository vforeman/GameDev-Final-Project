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
    // initialize("Circle");
    Graphics::createCircle(_verts,_norms);
    createSimplePatrol();
}

void Enemy::attack(Vector3f target)
{

}

void Enemy::createSimplePatrol()
{
    unsigned int rangeX = util::xorshift()%42;
    unsigned int rangeZ = util::xorshift()%42;
    Vector3f pos = _position;
    float floating = (float)(util::randomRange(0,50)%50)/100.0;
    floating *= _position.y<0,5 ? 1 : -1;

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
    pos.x += rangeX;
    _patrolPath.push_back(pos);

    pos.z += rangeX;

    _patrolPath.push_back(pos);
    pos.x -= rangeX;
    _patrolPath.push_back(pos);
    pos.z -= rangeZ;
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
            _velocity = _patrolPath[_point] - _position;//_velocity is a physics entity attribute
            _velocity.normalize();
            _position = _position + _velocity*0.125f;
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
