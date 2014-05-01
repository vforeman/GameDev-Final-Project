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
Weapon::Weapon() : _coolDown(4)
{
    _reloading = false;
    _clip = 0;
    _maxClipSize = 8;
    _magazine = new Bullet*[_maxClipSize];
    for(unsigned int i = 0; i < _maxClipSize; ++i)
    {
        _magazine[i] = new Bullet();
    }
}

//Overloaded constructor to give weapons more ammo
Weapon::Weapon(unsigned int clipSize) : _clip(0), _reloading(false), _coolDown(4)
{
    _maxClipSize = clipSize;
    _magazine = new Bullet*[_maxClipSize];
    for(unsigned int i = 0; i < _maxClipSize; ++i)
    {
        _magazine[i] = new Bullet();
    }
}

unsigned int Weapon::getClip()
{
    return _clip;    
}

void Weapon::fire(Vector3f pos, Vector3f target)
{
	Vector3f temp = pos;
	//temp.x /= 10;
	//temp.y /= 10;
	//temp.z /= 10;
	std::cout<<"temp: "<<temp<<std::endl;
	//target *=10;
	std::cout<<"target: "<<target<<std::endl;
	

    if(_coolDown < 5)
    {
        _coolDown = 10;
        Bullet* b = new Bullet(pos);    //Create a bullet object
        // b->_velocity=(target - pos)*0.03125f;    //Fire it at the target from position
       b->_velocity=(target-pos);    //Fire it at the target from position 
	//b->_velocity=(temp - pos);    //Fire it at the target from position 
        b->_velocity.normalize();
        //b->_velocity = b->_velocity;
        ++_clip;                        //If emptied clip reset to 0
        if(_clip >= _maxClipSize)
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
    if(_coolDown >= 5)
    {
        --_coolDown;
    }
        
        for(unsigned int i = 0; i < _clip ; ++i)
        {
            if(_magazine[i] != NULL && _magazine[i]->_active)
                _magazine[i]->update();
        }
}

void Weapon::reload()
{
    for(unsigned int i = 0; i < _maxClipSize; ++i)
        _magazine[i]->_active = false;
}

Bullet* Weapon::getBullet(unsigned int index)
{
    return _magazine[index];
}
}// namespace physics
