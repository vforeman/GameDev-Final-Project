#include <string>
#include "WindowController.h"
#include "PhysicsEngine.h"
#include "LevelFactory.h"
#include "GraphicsRenderer.h"
#include "Util.h"
#include "GameLogic.h"

using namespace window;
using namespace physics;
using namespace level;
using namespace graphics;
using namespace std;

int main()
{
    Window * wCtrl = Window::getInstance();
	GameLogic* gameObject = GameLogic::getInstance();
	gameObject->start();
 

 return 0;
}
