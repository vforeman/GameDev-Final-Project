#include "src/Graphics.h"

Graphics::Graphics() : initialized(false)
{

}

void createCircle(std::vector<float>& verts);
void Graphics::initialize(std::string type)
{
    //Add functionality to create different shapes with if statement
    if(!initialized)
    {
        if(type == "circle" || type == "Circle" || type == "CIRCLE")
            createCircle(verts);
        else
            createCircle(verts);
    }
    initialized = true;
}

void createCircle(std::vector<float>& verts)
{
    
}
