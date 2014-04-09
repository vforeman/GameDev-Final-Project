#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Vmath.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>

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

class Sphere
{
public:
	float _x;
	float _y;
	float _z;
	float _radius;
	float _resol;
	std::vector<GLfloat> _verts;
	std::vector<GLfloat> _normals;

	Sphere();
	Sphere(float,float);
	void draw();
	void initialize();
private:
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
