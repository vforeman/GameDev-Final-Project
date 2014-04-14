/**@Dependencies:
*	Vmath.h
**/#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Vmath.h"
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
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

void genCircleVertices(vector<float> *);

class Sphere
{
public:
Sphere();
~Sphere();
vector<float> _verts;
vector<float>::const_iterator _v;

private:
	float angle1,angle2;
float definition;
void genCircleVertices();
};

} // namspace geo
#endif //GEOMETRY_H
