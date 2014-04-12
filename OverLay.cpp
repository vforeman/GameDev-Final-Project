#include "OverLay.h"

OverLay::Overlay()
{
	Initialize();
};
OverLay:~Overlay()
{

};
void OverLay:: GenerateOverlay()
{

};
bool OverLay:: isObstacle(Vector3<float>)
{

};
bool OverLay:: isObstacle(int, int, int)
{

};

void Initialize()
{
	for(unsigned int i = 0; i < 20; ++i)
        for(unsigned int j = 0; j < 20; ++j)
            _overlay[i][j] = 'F';

	 for(unsigned int i = 0; i < 5; ++i)
        Generator::Random(); // Random function from util class instead of generator, Random function was a intermediate call to the Rand() function

	constructQuadrant( _overlay, 20, 20);


};

void constructQuadrant()
{
    
    for(unsigned int i = 0; i < row; ++i)
        for(unsigned int j = 0; j < col; ++j)
        {
            if(Generator::Random() % 100 >= 90)
                quad[i][j] = 'W';
        }
};

