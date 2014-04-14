#ifndef OVERLAY_H
#define OVERLAY_H
#include "Vmath.h"
#include "Util.h"

using namespace util;

class Overlay
{
	public:
		Overlay();
		~Overlay();
		void GenerateOverlay();
		static bool isObstacle(Vector3f);
		static bool isObstacle(int, int, int);
		void constructQuadrant();

		static char ** _overlay;
	private:
		static int OVERLAY_HEIGHT;
		static int OVERLAY_WIDTH;
		void initialize();

};

#endif
