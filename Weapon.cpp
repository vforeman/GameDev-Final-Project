#include "src/Weapon.h"



namespace physics{

int Weapon::MAX_CLIP_SIZE = 8;

Weapon::Weapon()
{
    _reloading = false;
    _clip = 0;
}

void Weapon::fire(/*Vector3f target*/)
{
}

void Weapon::iterate()
{
    for(unsigned int i = 0; i < _clip ; ++i)
        _magazine.update();
}

void reload()
{

}
}// namespace physics
