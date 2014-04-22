#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <vector>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Vmath.h"
#include <cmath>
using namespace std;

const float RESOL = 0.125f;

//GRAPHIC COLORS
//Rainbow
const float RED[] = {1.0f, 0.0f, 0.0f};
const float ORANGE[] = {1.0f, 0.4f, 0.0f};
const float YELLOW[] = {1.0f, 1.0f, 0.0f,0.5f};
const float GREEN[] = {0.0f, 1.0f, 0.0f};
const float BLUE[] = {0.0f, 0.0f, 1.0f,0.5f};
const float INDIGO[] = {0.4f, 0.0f, 0.4f,0.5f};
const float VIOLET[] = {0.4f, 0.0, 1.0f,0.5f};
const float BLACK[] = {0.0f, 0.0f, 0.0f,0.5f};
const float WHITE[] = {0.0f, 0.0f, 0.0f,0.5f};

//Specialized COlors
const float SKYBLUE[] = {0.49f, 0.75f, 0.93f};

class Graphics
{
    public:
        Graphics();
        virtual void initialize(std::string);
        void drawSphere();
								static void createCircle(std::vector<float>& verts,std::vector<float>& norms);
        std::vector<float> _verts;
        std::vector<float> _norms;
    protected:
        bool _initialized;
};

#endif
