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
#include "Level.h"
#include "Geometry.h"
using namespace std;
using namespace geo;
using namespace util;
namespace graphics{




class Renderer
{
public:
	static Renderer * get();
	~Renderer();
 void init();//start drawing pipeline
	void drawStatic();//draw ModelAsset reference
	void drawStatic(Level);
	void drawLevel();
	void drawSphere();
	void drawDynamic();

private:
	Level _level;
	Sphere s;
	static Renderer * _instance;
	static bool _instanceFlag;
	Renderer();

 GLuint loadTextureFile();

};




}// namespace graphic
#endif //GRAPHICSRENDERER_H
