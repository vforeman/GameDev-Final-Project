#ifndef LEVELTEST_H
#define LEVELTEST_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "Overlay.h"
#include <vector>

class Level
{
	public:
		Level();
		// void buildLevel(float x, float z, unsigned int i, unsigned int j);
		void CreateWallPoints(Overlay);


		Overlay createOverlay;
};



#endif
