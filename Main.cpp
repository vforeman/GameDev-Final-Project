#include <string>
#include "WindowController.h"
#include "PhysicsEngine.h"
#include "LevelFactory.h"
#include "GraphicsRenderer.h"
#include "Util.h"

using namespace window;
using namespace physics;
using namespace level;
using namespace graphics;
using namespace std;

int main()
{
 Window * wCtrl = Window::getInstance();
 PhysicsEngine * pEng = PhysicsEngine::getInstance();
 Renderer * gren = Renderer::getInstance();
 Level *lvl;
 LevelFactory * lvlFactory;
 lvl = lvlFactory->CreateLevel("Flat");

 return 0;
}
