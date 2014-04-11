/**@Dependencies
*	Vmath.h
**/
#ifndef GRAPHICSRENDERER_H
#define GRAPHICSRENDERER_H
#include <GL/gl.h>
#include <GL/glu.h>
#include "Vmath.h"
namespace graphics{

class Renderer
{
public:
	static Renderer * get();
	~Renderer();
 void init();//start drawing pipeline
private:
	static Renderer * _instance;
	static bool _instanceFlag;
	Renderer();
	void drawStatic();//draw static objects
	void drawDynamic();//draw dynamic data

};



}// namespace graphic
#endif //GRAPHICSRENDERER_H
