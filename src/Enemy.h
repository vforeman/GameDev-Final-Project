/**@Dependencies:
*	Util.h	Vmath.h	PhysicsEngine.h
**/
#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "PhysicsEngine.h"
#include "AIManager.h"
#include "Vmath.h"
#include "Util.h"
#include "Graphics.h"
#include "Weapon.h"

namespace physics{
/***********************************
*                   ENEMY SPECIFICATION
*************************************/
class Enemy : public PhysicsEntity, virtual public Graphics
{
public:
    Enemy();
    Enemy(Vector3f);
    int _health;
    const float _ALERT_RADIUS;
    void attack(Vector3f);
    void die();
    void patrol(Vector3f);
    std::vector<float> _verts;
    std::vector<float> _norms;
protected:
    bool _alive;
    bool _alert;
    unsigned int _point;    //Point on patrol path, treated as iterator
    std::vector< Vector3f > _patrolPath;
    void createSimplePatrol();
    void createStrongPatrol();
    void target();
    Weapon _weapon;
};
}//namespace physics
#endif// ENEMY_H
