/**@Dependencies:
*	Vmath.h
**/#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Vmath.h"
namespace geo{

class Rectangle
{
private:
	int _x;
	int _y;
	int _w;
	int _h;
public:
	Rectangle();
 Rectangle( Vector4f );
 Rectangle( float, float, float, float);
 Rectangle(int,int,int,int);
 ~Rectangle();
};

class BBox
{
public:
 BBox(int width,int length);
 BBox(int width, int length, Vector3f position);
 ~BBox();
private:
 int _width;
	int _length;
};




} // namspace geo
#endif //GEOMETRY_H
