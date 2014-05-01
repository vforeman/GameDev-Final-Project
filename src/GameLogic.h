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
#include "Player.h"
#include "Weapon.h"
#include "Graphics.h"
#include "Util.h"
#include "Overlay.h"
#include "SoundManager.h"
#include "Font.h"


using namespace util;
namespace logic{
/***********************************
*						GAME LOGIC SPECIFICATION
*************************************/
class GameLogic
{
private:
    GameLogic(const GameLogic&);
    GameLogic& operator=(const GameLogic&);
    GameLogic();
    void update();
	void show();
    void spawnEnemies();
    void displayMenu();
    void displayHUD();
    bool _fireSignal;
    int _difficulty = -1;
	const int NUMBER_OF_ENEMIES = 5;
    unsigned int _highscore = 0;
    unsigned int _score;
    freetype::font_data _gameFont;
    freetype::font_data _menuFont;
    freetype::font_data _titleFont;
public:
	void restart();
    bool _active;           //If the player dies the game is not active
    bool _running;
    bool _opposition;       //Are any enemies alive?
	//physics::PhysicsEngine * _pEngine;
	//window::Window * _wController;
    std::vector<physics::Enemy*> _enemies;
	Camera * _cam;
    Player * _player;
    physics::Weapon * _weapon;
	//gamein::InputController * _iController;
	//graphics::Renderer * _renderer;
	static GameLogic& get();
    void run();
	void start();
	//void ranjaytest(std::vector<Vector2<float> >& e, std::vector<Vector2<float> >& le);

};










}//namespace logic
#endif //GAMELOGIC_H
