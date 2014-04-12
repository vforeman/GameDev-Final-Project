#include "OverLay.h"

OverLay::OverLay()
{
	initialize();
}
OverLay::~OverLay()
{

}
void OverLay::GenerateOverlay()
{

}
bool OverLay::isObstacle(Vector3<float>)
{

}
bool OverLay::isObstacle(int, int, int)
{

}

void OverLay::initialize()
{
	for(unsigned int i = 0; i < 20; ++i)
        for(unsigned int j = 0; j < 20; ++j)
            _overlay[i][j] = 'F';

	 for(unsigned int i = 0; i < 5; ++i)
        // Generator::Random(); // Random function from util class instead of generator, Random function was a intermediate call to the Rand() function

	constructQuadrant();


}

void OverLay::constructQuadrant()
{

    for(unsigned int i = 0; i < 20; ++i)
        for(unsigned int j = 0; j < 20; ++j)
        {
            if(xorshift() % 100 >= 90)
            {
                _overlay[i][j] = 'W';

            }

        }
}


