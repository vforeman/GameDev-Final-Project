#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H
#include <GL/gl.h>
#include <GL/glu.h>
#include "Vmath.h"
#include "Camera.h"
namespace gamein{

class InputController
{
public:
	static InputController * get();
	~InputController();
	bool HandleInput(Camera * cam,bool running);
private:
	static InputController * _instance;
	static bool _instanceFlag;
	InputController();
};
}// namespace gamein
#endif //INPUTCONTROLLER_H
