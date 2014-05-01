#include "src/Enemy.h"
namespace physics{


Enemy::Enemy() : _health(100),  _alive(true), _point(0),
                 _alert(false), alertRadius(20.0f)
{
    _position = Vector3f(42.0f, 0.5f, 42.0f);   //Arbitrary position 
    Graphics::createCircle(_verts, _norms);
    createStrongPatrol();
}

Enemy::Enemy(Vector3f pos) : _health(100), _alive(true), _point(0),
                             _alert(false), alertRadius(20.0f)
{
    _position = pos;
    Graphics::createCircle(_verts,_norms);
    createStrongPatrol();
}

bool Enemy::isLiving()
{
    if(!_alive)
    {
        return false;
    }
    else if(_health <= 0)
    {
        die();
        return false;
    }

    return _alive;
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

void Enemy::decreaseHealth()
{
    _health -= 10;
}

void Enemy::decreaseHealth(int damage)
{
    switch(damage)
    {
        case 0:
            _health -= 100;
            break;
        case 1:
            _health -= 50;
            break;
        case 2:
            _health -= 25;
            break;
        default:
            _health -= 10;
            break;
    }
}

void Enemy::die()
{
    _alive = false;
}

void Enemy::patrol(Vector3f target)
{

    if(physics::PhysicsEngine::spheresphere(_position, alertRadius, target, 0.5f) )
    {
        //Fire at player
        //_radius = 2.0f;
        if(_radius <= MAX_SIZE)
            _radius += GROWRATE;
       
        _weapon.fire(_position, target, true); 
        /*_velocity = target - _position;
        _velocity.normalize();
        _velocity = _velocity * 3.0f;
        _force = _velocity * 1.5f;
        update();
        */
    }
    else
    {
        //_radius = 0.5f;
        if(_radius >= MIN_SIZE)
            _radius -= GROWRATE;

        if(!_patrolPath.empty())
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
                if(_point >= _patrolPath.size() && !_searching)
                    _point = 0;
                else if(_point >= _patrolPath.size() && _searching)
                {
                    searchNDestroy();
                    _point = 0;
                }
            }
        }
    }
}

void Enemy::createStrongPatrol()
{
    Vector3f player = AIManager::getInstance().getPlayer();
    Vector3f dest;  //destination
    Node* path = AIManager::getInstance().astar(_position, player);
    if(path != NULL)
    {
        path->traverse(_patrolPath);
    }
    dest = AIManager::getInstance().randVec3f();
    path = AIManager::getInstance().astar(player, dest);
    if(path != NULL)
    {
        path->traverse(_patrolPath);
    }
    path = AIManager::getInstance().astar(dest, _position);
    if(path != NULL)
    {
        path->traverse(_patrolPath);
    }
}

void Enemy::searchNDestroy()
{
    _patrolPath.clear();
    _searching = true;
    Node *path = AIManager::getInstance().astar(_position, 
                                                AIManager::getInstance().getPlayer());
    if(path != NULL)
    {
        path->traverse(_patrolPath);
    }
}

void Enemy::target()
{
}

}//namespace physics
