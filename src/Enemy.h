#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "PhysicsEngine.h"
#include "Vmath.h"
#include "Util.h"

class Enemy : public PhysicsEntity
{
    public:
        Enemy();
        bool _alive;
        int _health;
        void attack();
        void die();
        void patrol();
    private:
        std::vector< Vector3f > patrolPath;
        void createSimplePatrol();
        void target();
};

#endif
