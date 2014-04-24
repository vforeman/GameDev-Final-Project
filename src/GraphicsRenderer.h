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
	static Renderer& get();
	Overlay _lvl;
	void drawStatic();
	void drawDynamic();
    void drawHud();
    void popBackGraphics();
    void registerGraphics(Graphics*);
    void emptyObjects();
	void playerDead(Vector3f);

private:
	Renderer();
    Renderer(const Renderer&);
    Renderer& operator=(const Renderer&);
	bool _textureFlag = false;
    GLuint _texture;
	static bool _firstDraw;
	static GLuint h_bullets;
    std::vector<Graphics*> _drawObjects;    //Register graphics objects i.e. Enemy
    GLuint loadBMP();
    void buildHudList();
};

}// namespace graphic
#endif //GRAPHICSRENDERER_H
