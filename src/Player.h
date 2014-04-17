#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsEngine.h"
#include "Camera.h"

/*******************************************************
 * PLAYER SPECIFICATION
*******************************************************/


class Player : public physics::PhysicsEntity
{
    public:
        Player();
        Player(Vector3f);
        Camera* getCamera();
        void decreaseHealth();
        void decreaseHealth(int);
        void increaseHealth();
        void increaseHealth(int);
    protected:
        Camera* _camera;
        int _health;
};


#endif
