/**@Dependencies:
*	Vmath.h	PhysicsEngine.h
**/
#ifndef WEAPON_H
#define WEAPON_H

#include "Vmath.h"
#include "PhysicsEngine.h"
#include "Graphics.h"
#include <string>
namespace physics{
/***********************************
*					BULLET SPECIFICATION
*************************************/
class Bullet : public PhysicsEntity, virtual public Graphics
{
public:
 Bullet();
 Bullet(Vector3f);
 bool _active;
 std::string _type;
};


class Weapon
{
public:
 Weapon();
 Weapon(unsigned int);
 unsigned int getClip();
 void fire(Vector3f, Vector3f, bool );  
 void iterate(); //Container iterate update on all bullets fired
 void reload();
 Bullet* getBullet(unsigned int);
private:
 bool _reloading;
 unsigned int _clip;
 unsigned int _coolDown;
 unsigned int _maxClipSize;
 Bullet** _magazine;
};
}// namespace physics
#endif //WEAPON_H
