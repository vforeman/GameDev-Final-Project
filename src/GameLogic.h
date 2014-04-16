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
public:
	physics::PhysicsEngine * _pEngine;
	window::Window * _wController;
    std::vector<physics::Enemy*> _enemies;
	Camera * _cam;
	gamein::InputController * _iController;
	graphics::Renderer * _renderer;
	static GameLogic * get();
	~GameLogic();
	std::vector<Vector3<float> > enempos;
    void run();
	void start();
	void ranjaytest(std::vector<Vector3<float> > e);

};










}//namespace logic
#endif //GAMELOGIC_H
