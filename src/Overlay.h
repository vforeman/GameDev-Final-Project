#ifndef OVERLAY_H
#define OVERLAY_H
#include "Vmath.h"
#include "Util.h"
#include <iostream>

using namespace util;

class Overlay
{
	public:
		Overlay();//calls initialize function
		~Overlay();
		static bool isObstacle(Vector3f);
		static bool isObstacle(int, int);
		void constructQuadrant();

		static char ** _overlay;
	private:
		static unsigned int OVERLAY_HEIGHT;
		static unsigned int OVERLAY_WIDTH;
		/**
		 * @details [instantiates each char in 2d array
		 * and assigned the value of 'F' as floor to each char.
		 * calls void constructQuadrant()]
		 */
		void initialize();

};

#endif
