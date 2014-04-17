#include "src/Weapon.h"



namespace physics{
/*--------->BULLET IMPLEMENTATION<-----------*/
Bullet::Bullet()
{
    _type = "";
}

Bullet::Bullet(Vector3f pos)
{
    _type = "";
    _position = pos;
}

/*--------->WEAPON IMPLEMENTATION<-----------*/
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

void Weapon::fire(Vector3f pos, Vector3f target)
{
    Bullet* b = new Bullet(pos);    //Create a bullet object
    b->_velocity=(target - pos);    //Fire it at the target from position

    ++_clip;                        //If emptied clip reset to 0
    if(_clip >= _MAX_CLIP_SIZE)
        _clip = 0;

    _magazine[_clip] = b;           //Place the bullet in _magazine i.e. fire away
                                    //Call weapon iterate to update bullet positions
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
