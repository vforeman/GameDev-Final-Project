/**@Dependencies:
*	PRIMITIVE
**/
#ifndef DUMMY_H
#define DUMMY_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <cstdlib>
#include "Vmath.h"
#define T_PI 3.1415926535
#define RESL 0.05

class Dummy
{
	public:
	Vector3<float> pos;
	void drawSphere();
	void drawEnvironment();
	void setPosition(float x, float y, float z);
	Vector3<float> getPosition();
 Dummy();
 ~Dummy();
};
#endif
