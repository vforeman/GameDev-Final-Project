#include "src/Geometry.h"
namespace geo{

Rectangle::Rectangle():_bound(Vector4f())
{}
Rectangle::Rectangle( Vector4f bound):_bound(bound)
{}
Rectangle::Rectangle( float x, float y, float z , float w ):_bound(Vector4f(x,y,z,w))
{}
Rectangle::~Rectangle()
{}
Vector4f * Rectangle::getBound()
{
	return &_bound;
}



BBox::BBox(int width, int length):_width(width),_length(length)
{}
BBox::~BBox()
{}

Sphere::Sphere()
:definition(300)
{
 genCircleVertices();
 _v=_verts.begin();
}
Sphere::~Sphere(){}
void Sphere::genCircleVertices()
{
	float angle1,angle2;
   for(angle2=-M_PI/2;angle2<M_PI/2;angle2+=definition){
     for(angle1=0.0;angle1<=M_PI*2+definition;angle1+=definition){
      _verts.push_back(cos(angle2)*cos(angle1));
      _verts.push_back(sin(angle2));
      _verts.push_back(cos(angle2)*sin(angle1));
      _verts.push_back(cos(angle2+definition)*cos(angle1));
      _verts.push_back(sin(angle2+definition));
      _verts.push_back(cos(angle2+definition)*sin(angle1));

     }

   }
}


}//namespace geo
