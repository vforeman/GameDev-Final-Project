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
private:
	Level _level;
	static Renderer * _instance;
	static bool _instanceFlag;
	Renderer();
	void drawDynamic();//draw dynamic data
 GLuint loadTextureFile();
};




}// namespace graphic
#endif //GRAPHICSRENDERER_H
