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
	level::LevelContainer * _lContainer;
	Dummy * _obj;
}DATA;

class GameLogic
{
private:
	void update();
	void show();

	static GameLogic * _instance;
	static bool _instanceFlag;
	GameLogic();
public:
	static DATA _data;
	level::MODEL * _objs;
	static GameLogic * get();
	~GameLogic();
	void start();

};


}//namespace logic
#endif //GAMELOGIC_H

