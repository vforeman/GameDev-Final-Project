#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H
#include <GL/gl.h>
#include <GL/glu.h>
#include "Vmath.h"
#include "Camera.h"

class InputController
{
public:
	static InputController * getInstance();
	~InputController();
	bool HandleInput(Camera& cam,bool running);

private:
	static InputController * _instance;
	static bool _instanceFlag;
	InputController();
};


#endif
