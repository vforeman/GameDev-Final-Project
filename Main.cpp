#include <string>
#include <cassert>
#include "src/WindowController.h"
#include "src/PhysicsEngine.h"
#include "src/LevelFactory.h"
#include "src/GraphicsRenderer.h"
#include "src/GameLogic.h"
#include "src/Util.h"
#include "src/Overlay.h"
#include <iostream>


using namespace window;
using namespace physics;
using namespace level;
using namespace graphics;
using namespace std;
using namespace logic;


int main()
{

	GameLogic* gameObject = GameLogic::get();
	gameObject->start();


 return 0;
}


