#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "GraphicsRenderer.h"

namespace logic{
/***********************************
*						GAME LOGIC SPECIFICATION
*************************************/
class GameLogic
{
public:
	//starts gameloop
	void startGameloop();
	graphics::Renderer gren;
private:
	//mediates object updates between rendering
	void idle();




};









}//namespace logic
#endif //GAMELOGIC_H
