#include "src/Weapon.h"



namespace physics{
/*--------->BULLET IMPLEMENTATION<-----------*/
Bullet::Bullet() : _active(false)
{
    _type = "";
    initialize("Circle");
    _radius= 0.25f;
}

Bullet::Bullet(Vector3f pos) : _active(false)
{
    _type = "";
    _position = pos;
    initialize("Circle");
    _radius = 0.25f;
}

/*--------->WEAPON IMPLEMENTATION<-----------*/
Weapon::Weapon() : _MAX_CLIP_SIZE(8), _coolDown(200)
{
    _reloading = false;
    _clip = 0;
    _magazine = new Bullet*[_MAX_CLIP_SIZE];
}

//Overloaded constructor to give weapons more ammo
Weapon::Weapon(unsigned int clipSize) : _MAX_CLIP_SIZE(clipSize), _clip(0), _reloading(false), _coolDown(100)
{
    _magazine = new Bullet*[_MAX_CLIP_SIZE];
}

unsigned int Weapon::getClip()
{
    return _clip;    
}

void Weapon::fire(Vector3f pos, Vector3f target)
{
    //printf("Position: (%.2f, %.2f, %.2f)\n", pos.x, pos.y, pos.z);
    //printf("  Target: (%.2f, %.2f, %.2f)\n", target.x, target.y, target.z);
    --_coolDown;
    if(_coolDown < 5)
    {
        _coolDown = 200;
        Bullet* b = new Bullet(pos);    //Create a bullet object
        b->_velocity=(target - pos)*0.03125f;    //Fire it at the target from position

        ++_clip;                        //If emptied clip reset to 0
        if(_clip >= _MAX_CLIP_SIZE)
        {
            _clip = 0;
            reload();
        }
        b->_active = true;
        _magazine[_clip] = b;           //Place the bullet in _magazine i.e. fire away
                                    //Call weapon iterate to update bullet positions
    }
}

void Weapon::iterate()
{
    if(_coolDown <= 5)
    {
        for(unsigned int i = 0; i < _clip ; ++i)
        {
            //printf("WEAPON: ITERATE\n");
            if(_magazine[i] != NULL && _magazine[i]->_active)
                _magazine[i]->update();
        }
    }
    else
    {
        --_coolDown;
        for(unsigned int i = 0; i < _clip; ++i)
        {
            //printf("WEAPON: ITERATE2\n");
            if(_magazine[i] != NULL && _magazine[i]->_active)
                _magazine[i]->update();
        }
    }
}

void Weapon::reload()
{
    for(unsigned int i = 0; i < _MAX_CLIP_SIZE; ++i)
        _magazine[i]->_active = false;
}

Bullet* Weapon::getBullet(unsigned int index)
{
    return _magazine[index];
}
}// namespace physics
