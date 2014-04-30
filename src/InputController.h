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
	static InputController& get();
	bool HandleInput(Camera *, bool&, bool);
    bool getExitSignal();
	static bool _playerDead;
	static bool _respawn;
    void setExitSignal(bool);
    void setMouseHidden(bool);
private:
    bool _mouseHidden = false;
    bool _exitSignal = false;
    InputController(const InputController&);
    InputController& operator=(const InputController&);
	InputController();
};

}// namespace gamein
#endif //INPUTCONTROLLER_H
