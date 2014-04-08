#include "Geometry.h"
namespace geo{

Rectangle::Rectangle()
:_x(0),_y(0),_w(0),_h(0)
{}
Rectangle::Rectangle( Vector4f bound)
:_x(bound.x),_y(bound.y),_w(bound.z),_h(bound.w)
{}
Rectangle::Rectangle( float x, float y, float w, float h )
:_x(x),_y(y),_w(w),_h(h)
{}
Rectangle::Rectangle(int x, int y ,int w, int h)
:_x(x),_y(y),_w(w),_h(h)
{}
Rectangle::~Rectangle()
{}




BBox::BBox(int width, int length):_width(width),_length(length)
{}
BBox::~BBox()
{}







}//namespace geo
