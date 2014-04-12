#ifndef OVERLAY_H
#define OVERLAY_H
#include "Vmath.h"
#include "Util.h"

using namespace util;

class OverLay
{
	public:
		OverLay();
		~OverLay();
		void GenerateOverlay();
		static bool isObstacle(Vector3<float>);
		static bool isObstacle(int, int, int);
		void constructQuadrant();
	protected:
		 char _overlay[200][200];
	private:
		void initialize();

};

#endif
