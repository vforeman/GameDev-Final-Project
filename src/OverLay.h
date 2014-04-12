#ifndef OVERLAY_H
#define OVERLAY_H
#include "Constants.h"

class Overlay
{
	public:
		Overlay();
		~Overlay();
		void GenerateOverlay();
		static bool isObstacle(Vector3<float>);
		static bool isObstacle(int, int, int);
		void constructQuadrant();
	protected:
		 char _overlay[20][20];
	private:
		void initialize();
		
};

#endif
