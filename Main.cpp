#include <string>
#include <cassert>
#include "src/WindowController.h"
#include "src/PhysicsEngine.h"
#include "src/GraphicsRenderer.h"
#include "src/GameLogic.h"
#include "src/Util.h"
#include "src/Overlay.h"
#include <iostream>


using namespace window;
using namespace physics;
using namespace graphics;
using namespace std;
using namespace logic;
int main(int argc, char *argv[])
{
    alutInit(&argc, argv);
	GameLogic* gameObject = GameLogic::get();
	
    gameObject->start();
    gameObject->run();

 
    SoundManager::getInstance().stop();
    usleep(250);
    SoundManager::getInstance().close();
    usleep(250);
    alutExit();
    return 0;
}


