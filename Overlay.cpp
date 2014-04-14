<<<<<<< HEAD
#include "src/Overlay.h"

unsigned int Overlay::OVERLAY_HEIGHT = 200;
unsigned int Overlay::OVERLAY_WIDTH = 200;
char ** Overlay::_overlay = new char*[Overlay::OVERLAY_WIDTH];

Overlay::Overlay()
{
	initialize();
};
Overlay::~Overlay()
{
    for(int c = 0; c< Overlay::OVERLAY_HEIGHT;++c)
    {
        delete[] _overlay[c];
    }
    delete[] _overlay;
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

bool Overlay::isObstacle(Vector3f pos)
{
	return _overlay[(int)pos.x][(int)pos.z] == 'W';
}
bool Overlay::isObstacle(int x, int z)
{
    return _overlay[x][z] == 'W';
}


void Overlay::initialize()
{
    for(int c = 0; c< Overlay::OVERLAY_HEIGHT;++c)
    {
        _overlay[c] = new char[Overlay::OVERLAY_HEIGHT];
    }
	for(unsigned int i = 0; i < Overlay::OVERLAY_HEIGHT; ++i)
        for(unsigned int j = 0; j < Overlay::OVERLAY_WIDTH; ++j)
            _overlay[i][j] = 'F';
        //!!this for loop does absolutely nothing
	 /*for(unsigned int i = 0; i < 5; ++i)
        xorshift(); // Random function from util class instead of generator, Random function was a intermediate call to the Rand() function*/

	constructQuadrant();


};

void Overlay::constructQuadrant()
{

    for(unsigned int i = 0; i < Overlay::OVERLAY_HEIGHT; ++i)
        for(unsigned int j = 0; j < Overlay::OVERLAY_WIDTH; ++j)
        {
            int opt = randomRange(0,100) % 100;
            std::cout<<opt<<std::endl;
            if( opt>= 90)
                cout<<"wall"<<endl;
                _overlay[i][j] = 'W';
        }
};

