#include "src/Enemy.h"
namespace physics{


Enemy::Enemy() : _health(100),  _alive(true), _point(0),
                 _alert(false), _ALERT_RADIUS(20.0f)
{
    initialize("Circle");
//    createSimplePatrol();
    createStrongPatrol();
}

Enemy::Enemy(Vector3f pos) : _health(100), _alive(true), _point(0),
                             _alert(false), _ALERT_RADIUS(20.0f)
{
    _position = pos;
    // initialize("Circle");
    Graphics::createCircle(_verts,_norms);
//    createSimplePatrol();
    createStrongPatrol();
}

void Enemy::attack(Vector3f target)
{

}

void Enemy::createSimplePatrol()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned int> distribution(1, 42);
    unsigned int rangeX = distribution(generator);
    unsigned int rangeZ = distribution(generator);
    Vector3f pos = _position;
    float floating = (float)(util::randomRange(0,50)%50)/100.0;
    floating *= _position.y<0,5 ? 1 : -1;

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
        _radius = 2.0f;
        //_weapon.fire(_position, target);
    }
    else
    {
        _radius = 0.5f;
        if(!_patrolPath.empty())
        {
            if(!(_position.x - _patrolPath[_point].x < 0.25f && _position.x - _patrolPath[_point].x > -0.25f &&
                _position.y - _patrolPath[_point].y < 0.25f && _position.y - _patrolPath[_point].y > - 0.25f &&
                _position.z - _patrolPath[_point].z < 0.25f && _position.z - _patrolPath[_point].z > -0.25f  ))
            {
                _velocity = _patrolPath[_point] - _position;//_velocity is a physics entity attribute
                _velocity.normalize();
                _position = _position + _velocity*0.125f;
//                    printf("(%.2f, %.2f, %.2f)\n", _position.x, _position.y, _position.z);
            }
            else
            {
                ++_point;
                if(_point >= _patrolPath.size())
                    _point = 0;
//                    printf("(%.2f, %.2f, %.2f)\n", _position.x, _position.y, _position.z);
            }
        }
    }
}

void Enemy::createStrongPatrol()
{
    Vector3f pos = _position;
    Node* path = AIManager::getInstance().astar(pos, Vector3f(0.0f, 0.0f, 0.0f));
    if(path != NULL)
    {
        path->traverse(_patrolPath);
    }
    path = AIManager::getInstance().astar(Vector3f(0.0f, 0.0f, 0.0f), Vector3f(10.0f, 0.0f, 0.0f));
    if(path != NULL)
    {
        path->traverse(_patrolPath);
    }
    //_patrolPath.insert(_patrolPath.begin(), _patrolPath.crbegin(), _patrolPath.crend());
}

void Enemy::target()
{
}

}//namespace physics
