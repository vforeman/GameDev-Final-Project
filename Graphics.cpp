#include "src/Graphics.h"

Graphics::Graphics() : _initialized(false)
{
}

void createCircle(std::vector<float>& verts);
void Graphics::initialize(std::string type)
{
    //Add functionality to create different shapes with if statement
    if(!_initialized)
    {
        if(type == "circle" || type == "Circle" || type == "CIRCLE")
            createCircle(_verts);
        else
            createCircle(_verts);
        //_verts.push_back(0.0f);     _verts.push_back(0.0f);     _verts.push_back(0.0f);
        //_verts.push_back(1.0f);     _verts.push_back(0.0f);     _verts.push_back(0.0f);
        //_verts.push_back(0.5f);     _verts.push_back(1.0f);     _verts.push_back(0.0f);
    }
    _initialized = true;
}

void Graphics::drawSphere()
{
    float xx, yy, zz;
    float xxp, yyp, zzp;
    for(float angle2 = -3.1416f/2.0f; angle2 <= 3.1416f/2.0f; angle2 += RESOL)
    {
        glBegin(GL_TRIANGLE_STRIP);
        glLoadIdentity();
        for(float angle1 = 0.0f; angle1 <= 3.1416f*2.0f; angle1 += RESOL)
        {
            xx = cos(angle1)*cos(angle2);
            yy = sin(angle2);
            zz = sin(angle1)*cos(angle2);
    
            xxp = cos(angle1)*cos(angle2 + RESOL);
            yyp = sin(angle2 +RESOL);
            zzp = sin(angle1)*cos(angle2 + RESOL);
            glNormal3d(0, 0, 1);
            glVertex3f(xx, yy, zz);
            glVertex3f(xxp, yyp, zzp);
        }
        glEnd();
    }
}    


void createCircle(std::vector<float>& verts)
{
    float xx, yy, zz;
    float xxp, yyp, zzp;

    for(float angle2 = -3.1416f; angle2 <= 3.1416f; angle2 += RESOL)
    {
        for(float angle1 = 0.0f; angle1 <= 3.1416f*2.0f; angle1 += RESOL)
        {
            //xx = cos(angle1)*cos(angle2);
            //yy = sin(angle2);
            //zz = sin(angle1)*cos(angle2);
    
            //xxp = cos(angle1)*cos(angle2 + RESOL);
            //yyp = sin(angle2 +RESOL);
            //zzp = sin(angle1)*cos(angle2 + RESOL);

            xx = sin(angle2)*cos(angle1);
            yy = sin(angle2)*sin(angle1);
            zz = cos(angle2);
            
            verts.push_back(xx);            verts.push_back(yy);            verts.push_back(zz);
            //verts.push_back(xxp);           verts.push_back(yyp);           verts.push_back(zzp);
        }
    }
    //verts.push_back(0.0f);
}
