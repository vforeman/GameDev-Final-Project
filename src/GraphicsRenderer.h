/**@TODO
*	add state attributes
*
**/
#ifndef GRAPHICSRENDERER_H
#define GRAPHICSRENDERER_H
#include <GL/gl.h>
#include <GL/glu.h>
#include "Vmath.h"
#include "Assets.h"
#include "Util.h"
#include "Geometry.h"
#include <iostream>
#include "Overlay.h"
#include "Graphics.h"
#include "Enemy.h"
#include <string>
#include <vector>
#include <exception>

using namespace std;
using namespace geo;
using namespace util;
namespace graphics{

void inHudMode(int screen_width, int screen_height);
void outHudMode();
class Renderer
{
public:
	static Renderer * get();
	~Renderer();
	void drawStatic();
	void drawDynamic();
 void drawHud();
    void popBackGraphics();
    void registerGraphics(Graphics*);
    void emptyObjects();
	Overlay _lvl;

private:
	static Renderer * _instance;
	static bool _instanceFlag;
	static bool _firstDraw;
 std::vector<Graphics*> _drawObjects;    //Register graphics objects i.e. Enemy
	bool _textureFlag;
	Renderer();
	static GLuint h_bullets;
 GLuint loadBMP();
 GLuint _texture;
 void buildHudList();
};

}// namespace graphic
#endif //GRAPHICSRENDERER_H
