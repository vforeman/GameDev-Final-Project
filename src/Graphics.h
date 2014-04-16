#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <vector>
#include <string>
#include "Vmath.h"

const float RESOL = 0.25f;

//GRAPHIC COLORS
//Rainbow
const float RED[] = {1.0f, 0.0f, 0.0f};
const float ORANGE[] = {1.0f, 0.4f, 0.0f};
const float YELLOW[] = {1.0f, 1.0f, 0.0f};
const float GREEN[] = {0.0f, 1.0f, 0.0f};
const float BLUE[] = {0.0f, 0.0f, 1.0f};
const float INDIGO[] = {0.4f, 0.0f, 0.4f};
const float VIOLET[] = {0.4f, 0.0, 1.0f};
const float BLACK[] = {0.0f, 0.0f, 0.0f};
const float WHITE[] = {0.0f, 0.0f, 0.0f};

//Specialized COlors
const float SKYBLUE[] = {0.49f, 0.75f, 0.93f};

class Graphics
{
    public:
        Graphics();
        virtual void initialize(std::string);
        std::vector<float> _verts;
    protected:
        bool _initialized;
};

#endif
