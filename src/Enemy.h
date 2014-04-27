/**@Dependencies:
*	Util.h	Vmath.h	PhysicsEngine.h
**/
#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "PhysicsEngine.h"
#include <iostream>
#include "AIManager.h"
#include "Vmath.h"
#include "Util.h"
#include "Graphics.h"
#include "Weapon.h"
#include <cmath>

namespace physics{
/***********************************
*                   ENEMY SPECIFICATION
*************************************/
class Enemy : virtual public PhysicsEntity, virtual public Graphics
{
public:
    Enemy();
    Enemy(Vector3f);
    bool isLiving();
    void attack(Vector3f);
    void decreaseHealth();
    void decreaseHealth(int);
    void die();
    void patrol(Vector3f);
    std::vector<float> _verts;
    std::vector<float> _norms;
    Weapon _weapon;
protected:
    bool _alive;
    bool _alert;
    float alertRadius;
    int _health;
    unsigned int _point;    //Point on patrol path, treated as iterator
    std::vector< Vector3f > _patrolPath;
    void createSimplePatrol();
    void createStrongPatrol();
    void target();
};
}//namespace physics
#endif// ENEMY_H
