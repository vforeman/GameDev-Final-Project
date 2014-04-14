#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <vector>
#include <string>
#include "Vmath.h"

class Graphics
{
    public:
        Graphics();
        void initialize(std::string);
        std::vector<float> verts;
    protected:
        bool initialized;
};

#endif
