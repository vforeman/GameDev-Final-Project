#ifndef LIGHTING_H
#define LIGHTING_H

const float SHINE[] = {64.0f};   //Shine factor for reflection
const float EMISSION[] = {0.0f, 0.0f, 0.0f, 0.0f};

const float GREEN[] = {0.0f, 1.0f, 0.0f};
const float BLUE[]  = {0.0f, 0.0f, 1.0f};
const float RED[]   = {1.0f, 0.0f, 0.0f};
const float ORANGE[]= {1.0f, 0.4f, 0.0f};
const float INDIGO[]= {0.4f, 0.0f, 0.4f};
const float VIOLET[]= {0.4f, 0.0f, 1.0f};

class Light
{
    public:
        Light();
        Light(std::string);

    private:
        std::string type;   //Point or spot

};

#endif
