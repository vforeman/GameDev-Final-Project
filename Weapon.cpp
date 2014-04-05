#include "Weapon.h"

Bullet::Bullet()
{
    _type = "";
}


Weapon::Weapon()
{
    _reloading = false;
    _clip = 0;
}

void Weapon::fire(Vector3f target)
{
    

}

void Weapon::iterate()
{
    for(unsigned int i = 0; i < _clip; ++i)
        _magazine.update();
}

void reload()
{
    
}
