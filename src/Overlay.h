#ifndef OVERLAY_H
#define OVERLAY_H
#include "Generator.h"
#include "Vmath.h"
//#include "Constants.h"

class Overlay
{
	public:
		Overlay();
		~Overlay();
		//static char getObstacle(float radius,Vector3<float> pos);
		//static bool isObstacle(Vector3<float>);
		//static bool isObstacle(int, int, int);
		void ConstructQuadrant();
		char _overlay[20][20];
	protected:
		 
	private:
		void Initialize();
		
};

#endif
