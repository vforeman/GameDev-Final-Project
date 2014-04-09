#include "Geometry.h"
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


/*****************************
 *
 *  SPHERE IMPLEMENTATION
 *
 *
****************************/

Sphere::Sphere() : _x(0.0f), _y(0.0f), _z(0.0f),
                   _resol(0.25f), _radius(0.5f)
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
    glScalef(radius);
    glTranslatef(x, y, z);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    glNormalPointer(GL_FLOAT, 0 &normals[0]);

    glVertexPointer(3, GL_FLOAT, 0, &verts[0]);
    glDrawArrays(GL_TRIANGLES, 0, vertes.size());

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glPopMatrix();
}


void Sphere::initialize()
{
    float xx, yy, zz;
    float xxp, yyp, zzp;

    for(float angle2 = -3.1416f/2.0f; angle2 <= 3.1416f/2.0f; angle2 += resol)
    {
        for(float angle1 = 0.0f; angle1 <= 3.1416f*2.0f+resol; angle1 += resol)
        {
            xx = cos(angle1)*cos(angle2);
            yy = sin(angle2);
            zz = sin(angle1)*cos(angle2);

            xxp = cos(angle1)*cos(angle2 + resol);
            yyp = sin(angle2+ resol);
            zzp = sin(angle1)*cos(angle2 + resol);

            verts.push_back(xx);        verts.push_back(yy);        verts.push_back(zz);
            verts.push_back(xxp);       verts.push_back(yyp);       verts.push_back(zzp);
            normals.push_back(0.0f);    normals.push_back(0.0f);    verts.push_back(1.0f);
            
        }
    }
}

}//namespace geo
