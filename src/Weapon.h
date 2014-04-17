/**@Dependencies:
*	Vmath.h	PhysicsEngine.h
**/
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
 Weapon(unsigned int);
 unsigned int getClip();
 void fire(Vector3f, Vector3f);
 void iterate(); //Container iterate update on all bullets fired
 void reload();
 Bullet* getBullet(unsigned int);
private:
 bool _reloading;
 unsigned int _clip;
 const int _MAX_CLIP_SIZE;
 Bullet** _magazine;
};
}// namespace physics
#endif //WEAPON_H
