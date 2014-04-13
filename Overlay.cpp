#include "Overlay.h"
char Overlay::_overlay[][];
Overlay::Overlay()
{
	Initialize();
};
Overlay::~Overlay()
{

};

/*char Overlay::getObstacle(float radius,Vector3<float> pos)
{
    //A lot of variables for checking radius of sphere
    //For loop crashed the game
    char val = 'F';
    float x = pos.x;
    float z = pos.z;
    unsigned int i = 0;
    unsigned int j = 0;
     
            i = std::abs((int)roundf(x))/10;
            j = std::abs((int)roundf(z))/10;

            if(i >= 10 || j >= 10 || i < 0 || j < 0)
                return 'W';

            if(x >= 0.0f && z >= 0.0f)
               if(_overlay[i][j] == 'W')
                    return 'W';

            if(x <= 0.0f && z >=0.0f)
               if(_overlay[i][j] == 'W')
                    return 'W';

            if(x <= 0.0f && z <= 0.0f)
               if(_overlay[i][j] == 'W')
                    return 'W';

            if(x >= 0.0f && z <= 0.0f)
               if(_overlay[i][j] == 'W')
                    return 'W';

    return val;
} */

/*bool Overlay::isObstacle(Vector3<float>)
{
	return;
};
bool Overlay:: isObstacle(int, int, int)
{

};
*/

void Overlay::Initialize()
{
	for(unsigned int i = 0; i < 20; ++i)
        for(unsigned int j = 0; j < 20; ++j)
            _overlay[i][j] = 'F';

	 for(unsigned int i = 0; i < 5; ++i)
        Generator::Random(); // Random function from util class instead of generator, Random function was a intermediate call to the Rand() function

	ConstructQuadrant();


};

void Overlay::ConstructQuadrant()
{
    
    for(unsigned int i = 0; i < 20; ++i)
        for(unsigned int j = 0; j < 20; ++j)
        {
            if(Generator::Random() % 100 >= 90)
                _overlay[i][j] = 'W';
        }
};

