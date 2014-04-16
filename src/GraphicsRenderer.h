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
#include <string>
using namespace std;
using namespace geo;
using namespace util;
namespace graphics{




class Renderer
{
public:
	static Renderer * get();
	~Renderer();
	void drawStatic();
	void drawDynamic();
 void drawHud();
private:
	Overlay _lvl;
	static Renderer * _instance;
	static bool _instanceFlag;
	static bool _firstDraw;
	bool _textureFlag;
	Renderer();
 GLuint loadBMP();
 GLuint _texture;
};

}// namespace graphic
#endif //GRAPHICSRENDERER_H
