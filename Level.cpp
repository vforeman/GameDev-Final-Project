#include "Level.h"

Level::Level()
{



};
void Level::buildLevel(float x, float z, unsigned int i, unsigned int j)
{

                float addX = x;
                float addZ = z;
                //Front face of wall
                _wallPoints.push_back(x*float(i));         _wallPoints.push_back(0.0f);       _wallPoints.push_back(z*float(j));
                _wallPoints.push_back(x*float(i));         _wallPoints.push_back(10.0f);      _wallPoints.push_back(z*float(j));
                _wallPoints.push_back(x*float(i)+addX);     _wallPoints.push_back(10.0f);      _wallPoints.push_back(z*float(j));
                _wallPoints.push_back(x*float(i)+addX);     _wallPoints.push_back(0.0f);       _wallPoints.push_back(z*float(j));

                //Left face
                _wallPoints.push_back(x*float(i));         _wallPoints.push_back(0.0f);       _wallPoints.push_back(z*float(j));
                _wallPoints.push_back(x*float(i));         _wallPoints.push_back(10.0f);      _wallPoints.push_back(z*float(j));
                _wallPoints.push_back(x*float(i));         _wallPoints.push_back(10.0f);      _wallPoints.push_back(z*float(j)+addZ);
                _wallPoints.push_back(x*float(i));         _wallPoints.push_back(0.0f);       _wallPoints.push_back(z*float(j)+addZ);

                //Back Face
                _wallPoints.push_back(x*float(i));         _wallPoints.push_back(0.0f);       _wallPoints.push_back(z*float(j)+addZ);
                _wallPoints.push_back(x*float(i));         _wallPoints.push_back(10.0f);      _wallPoints.push_back(z*float(j)+addZ);
                _wallPoints.push_back(x*float(i)+addX);   _wallPoints.push_back(10.0f);      _wallPoints.push_back(z*float(j)+addZ);
                _wallPoints.push_back(x*float(i)+addX);   _wallPoints.push_back(0.0f);       _wallPoints.push_back(z*float(j)+addZ);

                //Right face
                _wallPoints.push_back(x*float(i)+addX);   _wallPoints.push_back(0.0f);       _wallPoints.push_back(z*float(j));
                _wallPoints.push_back(x*float(i)+addX);   _wallPoints.push_back(10.0f);      _wallPoints.push_back(z*float(j));
                _wallPoints.push_back(x*float(i)+addX);   _wallPoints.push_back(10.0f);      _wallPoints.push_back(z*float(j)+addZ);
                _wallPoints.push_back(x*float(i)+addX);   _wallPoints.push_back(0.0f);       _wallPoints.push_back(z*float(j)+addZ);
};


void Level::CreateWallPoints(Overlay createOverlay)
{

	 for(unsigned int i = 0; i < 10; ++i)
        for(unsigned int j = 0; j < 10; ++j)
        {
            if(createOverlay._overlay[i][j] == 'W')
            {
                //float x = 10.0f, z = 10.0f;
                buildLevel(10.0f, 10.0f, i, j);
            }
        }
    for(unsigned int i = 0; i < 10; ++i)
        for(unsigned int j = 0; j < 10; ++j)
        {
            if(createOverlay._overlay[i][j] == 'W')
            {
                //float x = -10.0f, z = 10.0f;
                buildLevel(-10.0f, 10.0f, i, j);
            }
        }
    for(unsigned int i = 0; i < 10; ++i)
        for(unsigned int j = 0; j < 10; ++j)
        {
            if(createOverlay._overlay[i][j] == 'W')
            {
                //float x = -10.0f, z = -10.0f;
                buildLevel(-10.0f, -10.0f, i, j);
            }
        }

    for(unsigned int i = 0; i < 10; ++i)
        for(unsigned int j = 0; j < 10; ++j)
        {
            if(createOverlay._overlay[i][j] == 'W')
            {
                //float x = 10.0f, z = -10.0f;
                buildLevel(10.0f, -10.0f, i, j);
            }
        }
};
