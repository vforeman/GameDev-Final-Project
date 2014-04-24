#include "src/Player.h"

Player::Player() : _health(100)
{
    _camera = new Camera();
}

Player::Player(Vector3f pos) : _health(100) 
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
   _health -= 1;
}

void Player::decreaseHealth(int damage)
{
    _health -= damage;
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
