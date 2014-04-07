/**@Dependencies:
*	Vmath.h
**/#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Vmath.h"
namespace geo{

class Rectangle
{
private:
	Vector4f _bound;
public:
	Rectangle();
 Rectangle( Vector4f );
 Rectangle( float, float, float, float);
 ~Rectangle();
 Vector4f * getBound();
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
