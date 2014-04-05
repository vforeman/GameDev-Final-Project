#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Vmath.h"
namespace geo{

class Rectangle
{
	Vector4f _bound;
public:
	Rectangle();
 Rectangle( Vector4f );
 Rectangle( float, float, float, float);
 ~Rectangle();
 Vector4f * getBound();
};






} // namspace geo
#endif //GEOMETRY_H
