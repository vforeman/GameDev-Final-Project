#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "Vmath.h"
#include "Camera.h"
#include "Weapon.h"

namespace gamein{

class InputController
{
public:
	static InputController * get();
	~InputController();
	bool HandleInput(Camera * ,bool);

private:
    bool _mouseHidden = false;
	static InputController * _instance;
	static bool _instanceFlag;
	InputController();
};

}// namespace gamein
#endif //INPUTCONTROLLER_H
