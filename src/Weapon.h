#ifndef WEAPON_H
#define WEAPON_H

#include "Vmath.h"
#include "PhysicsEngine.h"
#include <string>
namespace physics{



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
 static int MAX_CLIP_SIZE;
 Bullet _magazine;
};
}// namespace physics
#endif //WEAPON_H
