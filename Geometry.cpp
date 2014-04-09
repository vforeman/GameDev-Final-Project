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

/*****************************
 *
 *  SPHERE IMPLEMENTATION
 *
 *
****************************/

Sphere::Sphere()
: _x(0.0f), _y(0.0f), _z(0.0f), _radius(0.5f),_resol(0.25f)
{
    initialize();
}

Sphere::Sphere(float radius, float resol) : _x(0.0f), _y(0.0f), _z(0.0f),
                                            _radius(radius), _resol(resol)
{
    initialize();
}

void Sphere::draw()
{
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glScalef(_radius,_radius,_radius);
    glTranslatef(_x, _y, _z);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    glNormalPointer(GL_FLOAT, 0 ,&_normals);

    glVertexPointer(3, GL_FLOAT, 0, &_verts);
    glDrawArrays(GL_TRIANGLES, 0, _verts.size());

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glPopMatrix();
}


void Sphere::initialize()
{
    float xx, yy, zz;
    float xxp, yyp, zzp;

    for(float angle2 = -3.1416f/2.0f; angle2 <= 3.1416f/2.0f; angle2 += _resol)
    {
        for(float angle1 = 0.0f; angle1 <= 3.1416f*2.0f+_resol; angle1 += _resol)
        {
            xx = cos(angle1)*cos(angle2);
            yy = sin(angle2);
            zz = sin(angle1)*cos(angle2);

            xxp = cos(angle1)*cos(angle2 + _resol);
            yyp = sin(angle2 + _resol);
            zzp = sin(angle1)*cos(angle2 + _resol);

            _verts.push_back(xx);        _verts.push_back(yy);        _verts.push_back(zz);
            _verts.push_back(xxp);       _verts.push_back(yyp);       _verts.push_back(zzp);
            _normals.push_back(0.0f);    _normals.push_back(0.0f);    _verts.push_back(1.0f);

        }
    }
}


}//namespace geo
