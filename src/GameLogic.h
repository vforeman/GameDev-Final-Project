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
//#include "SoundManager.h"

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
	static GameLogic * _instance;
	static bool _instanceFlag;
	GameLogic();
	const int NUMBER_OF_ENEMIES = 5;
public:
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
	std::vector<Vector2<float> > enempos;
	std::vector<Vector2<float> > lineEndpts;
    void run();
	void start();
	void ranjaytest(std::vector<Vector2<float> >& e, std::vector<Vector2<float> >& le);

};










}//namespace logic
#endif //GAMELOGIC_H
