#ifndef GRAPHICSRENDERER_H
#define GRAPHICSRENDERER_H
#include <GL/gl.h>
#include <GL/glu.h>
#include "Vmath.h"
namespace graphics{

class Renderer
{
public:
	static Renderer * getInstance();
	~Renderer();

private:
	static Renderer * _instance;
	static bool _instanceFlag;
	Renderer();
};



}// namespace graphic
#endif //GRAPHICSRENDERER_H
