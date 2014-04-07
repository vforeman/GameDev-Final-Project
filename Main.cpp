#include <string>
#include "WindowController.h"
#include "PhysicsEngine.h"
#include "LevelFactory.h"
#include "GraphicsRenderer.h"
#include "GameLogic.h"
#include "Util.h"
#include <iostream>


using namespace window;
using namespace physics;
using namespace level;
using namespace graphics;
using namespace std;
using namespace logic;

int main()
{
 cout<<util::xorshift()%2<<endl;
/* Window * wCtrl = Window::get();*/
	GameLogic* gameObject = GameLogic::get();
	gameObject->start();


 return 0;
}
