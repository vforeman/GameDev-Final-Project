#include "src/Player.h"

Player::Player() : _health(200)
{
    _camera = new Camera();
}

Player::Player(Vector3f pos) : _health(200) 
{
    _position = pos;
    _camera = new Camera(pos);
}

Camera* Player::getCamera()
{
    return _camera;
}

bool Player::isAlive()
{
    if(_health <= 0) 
        return false;

    return true;
}

int Player::getHealth()
{
    return _health;
}

void Player::decreaseHealth()
{
   _health -= 5;
}

void Player::decreaseHealth(int damage)
{
    switch(damage)
    {
        case 0:
            _health -= 1;
            break;
        case 1:
            _health -= 2;
            break;
        case 2:
            _health -= 5;
            break;
        case 3:
            _health -= 10;
            break;
        case 4:
            _health -= 25;
            break;
        case 5:
            _health -= 50;
            break;
        default:
            _health -= 100;
            break;
    }
}

void Player::increaseHealth()
{
    _health += 5;
}

void Player::increaseHealth(int healthPak)
{
    _health += healthPak;
}

void Player::setHealth(int health)
{
    _health = health;
}
