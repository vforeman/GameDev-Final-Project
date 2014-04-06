#include "Geometry.h"
namespace geo{

Rectangle::Rectangle()
{
	_bound = Vector4f();
}
Rectangle::Rectangle( Vector4f bound)
{
 _bound = bound;
}
//x,y,z == position in mesh, w = occuppied
Rectangle::Rectangle( float x, float y, float z , float w )
{
 _bound = Vector4f(x,y,z,w);
}

Rectangle::~Rectangle()
{
}

Vector4f * Rectangle::getBound()
{
	return &_bound;
}
}//namespace geo
