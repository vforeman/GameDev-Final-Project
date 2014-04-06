#ifndef GAMELOGIC_H
#define GAMELOGIC_H



#include <GL/gl.h>
#include <GL/glu.h>
#include "Dummy.h"
#include "InputController.h"
#include "WindowController.h"
#include "Camera.h"

//Dummy.h is a temp class for drawing objects
using namespace window;
namespace logic{
/***********************************
*						GAME LOGIC SPECIFICATION
*************************************/
class GameLogic
{
	private:
	Camera cam;
	InputController* iController;
	Window * wController;

	void update();
	void show();
	static GameLogic * _instance;
	static bool _instanceFlag;
	GameLogic();

	public:
	static GameLogic * getInstance();
	Dummy obj;
	~GameLogic();

	void start();

};









}//namespace logic
#endif //GAMELOGIC_H
