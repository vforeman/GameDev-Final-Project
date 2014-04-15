#include "src/Weapon.h"



namespace physics{

Weapon::Weapon() : _MAX_CLIP_SIZE(8)
{
    _reloading = false;
    _clip = 0;
    _magazine = new Bullet*[_MAX_CLIP_SIZE];
}

//Overloaded constructor to give weapons more ammo
Weapon::Weapon(unsigned int clipSize) : _MAX_CLIP_SIZE(clipSize), _clip(0), _reloading(false)
{
    _magazine = new Bullet*[_MAX_CLIP_SIZE];
}
void Weapon::fire(/*Vector3f target*/)
{
    
}

void Weapon::iterate()
{
    for(unsigned int i = 0; i < _clip ; ++i)
        _magazine[i]->update();
}

void reload()
{

}
}// namespace physics
