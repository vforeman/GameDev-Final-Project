#ifndef LEVELTEST_H
#define LEVELTEST_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include "Generator.h"
//#include "Constants.h"
#include "Overlay.h"

class Level
{
	public:
		Level();
		void buildLevel(float x, float z, unsigned int i, unsigned int j);
		void CreateWallPoints(Overlay);
	private:
		std::vector<float> _wallPoints;
		Overlay createOverLay;
};



#endif
