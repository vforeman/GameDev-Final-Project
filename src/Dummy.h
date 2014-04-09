#ifndef DUMMY_H
#define DUMMY_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <cstdlib>
#define T_PI 3.1415926535
#define RESL 0.05

class Dummy
{
	public:
	void drawSphere();
	void drawEnvironment();
 Dummy();
 ~Dummy();
};
#endif
