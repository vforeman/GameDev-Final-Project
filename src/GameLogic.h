#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "InputController.h"
#include "WindowController.h"
#include "GraphicsRenderer.h"
#include "PhysicsEngine.h"
#include "Camera.h"
#include "Enemy.h"
#include "Player.h"
#include "Weapon.h"
#include "Graphics.h"
#include "Util.h"
#include "Overlay.h"
#include "SoundManager.h"

using namespace util;
namespace logic{
/***********************************
*						GAME LOGIC SPECIFICATION
*************************************/
class GameLogic
{
private:
	void update();
	void show();
    void spawnEnemies();
	static GameLogic * _instance;
	static bool _instanceFlag;
    bool _fireSignal;
	GameLogic();
    int _difficulty = 0;
	const int NUMBER_OF_ENEMIES = 5;
public:
    bool _active;           //If the player dies the game is not active
    bool _running;
    bool _opposition;       //Are any enemies alive?
	physics::PhysicsEngine * _pEngine;
	window::Window * _wController;
    std::vector<physics::Enemy*> _enemies;
	Camera * _cam;
    Player * _player;
    physics::Weapon * _weapon;
	gamein::InputController * _iController;
	graphics::Renderer * _renderer;
	static GameLogic * get();
	~GameLogic();
    void run();
	void start();

};










}//namespace logic
#endif //GAMELOGIC_H
