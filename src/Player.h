#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsEngine.h"
#include "Camera.h"

/*******************************************************
 * PLAYER SPECIFICATION
*******************************************************/


class Player : virtual public physics::PhysicsEntity
{
    public:
        Player();
        Player(Vector3f);
        Camera* getCamera();
        bool isAlive();
        int getHealth();
        void decreaseHealth();
        void decreaseHealth(int);
        void increaseHealth();
        void increaseHealth(int);
        void setHealth(int);
        void restart();
    protected:
        Camera* _camera;
        int _health;
};


#endif
