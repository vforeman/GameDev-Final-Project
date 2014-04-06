#ifndef WEAPON_H
#define WEAPON_H

#include "Vmath.h"
#include "PhysicsEngine.h"
#include <string>

struct Bullet : public PhysicsEntity
{
    Bullet();
    std::string _type;
};

class Weapon
{
    public:
        Weapon();
        void fire(Vector3f);
        void iterate(); //Container iterate update on all bullets fired
        void reload();
    private:
        bool _reloading;
        unsigned int _clip;
        Bullet _magazine[8];
};

#endif
