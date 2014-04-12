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
	static bool isObstacle(Vector3f);
	static bool isObstacle(int,int,int);
private:
	void constructQuadrant();


};








#endif
