#ifndef OVERLAY_H
#define OVERLAY_H
#include "Vmath.h"
#include "Util.h"

using namespace util;

class Overlay
{
	public:
		Overlay();//calls initialize function
		~Overlay();
		void GenerateOverlay();
		static bool isObstacle(Vector3f);
		static bool isObstacle(int, int, int);
		void constructQuadrant();

		static char ** _overlay;
	private:
		static unsigned int OVERLAY_HEIGHT;
		static unsigned int OVERLAY_WIDTH;
		/**
		 * @details [instantiates each char in 2d array
		 * and assigned the value of 'F' as floor to each char]
		 */
		void initialize();

};

#endif
