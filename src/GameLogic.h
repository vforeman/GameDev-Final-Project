/**@Dependencies:
	Dummy.h	LevelFactory.h	WindowController.h	GraphicsRenderer.h	Camera.h	\
	PhysicsEngine.h InputController.h
**/
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "Dummy.h"
#include "LevelFactory.h"
#include "InputController.h"
#include "WindowController.h"
#include "GraphicsRenderer.h"
#include "PhysicsEngine.h"
#include "Camera.h"

//Dummy.h is a temp class for drawing objects
namespace logic{
/***********************************
*						GAME LOGIC SPECIFICATION
*************************************/
typedef struct
{
	Camera * _cam;
	gamein::InputController * _iController;
	window::Window * _wController;

	Dummy * _obj;
}DATA;

class GameLogic
{
private:
	void update();
	void show();
	static DATA _data;
	static GameLogic * _instance;
	static bool _instanceFlag;
	GameLogic();
public:
	level::LevelContainer * _level;
	level::LevelFactory * _lFactory;
	window::Window * _wController;
	Camera * _cam;
	gamein::InputController * _iController;
	static GameLogic * get();
	~GameLogic();
	void start();

};










}//namespace logic
#endif //GAMELOGIC_H
