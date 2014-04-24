#ifndef OVERLAY_H
#define OVERLAY_H

#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include "Vmath.h"
#include "Util.h"
#include "Assets.h"
#include "levels.h"

using namespace std;
using namespace util;

class Overlay
{
	public:
		Overlay();//calls initialize function
		~Overlay();
		static bool isObstacle(Vector3f);
  static bool isObstacle(float, float, float);
		static bool isObstacle(float, float);
		static vector<GLfloat> _staticVertices;
		static vector<GLfloat> _staticNormals;
		static vector<GLfloat> _staticColors;
		static vector<GLshort> _staticTexCoords;
		static vector<GLuint> _staticIndex;
		static unsigned int OVERLAY_HEIGHT;
		static unsigned int OVERLAY_WIDTH;
		static float OVERLAY_HF;
		static float OVERLAY_WF;
		static int OVERLAY_HI;
		static int OVERLAY_WI; 
	private:
		vector<GLfloat>::iterator _floatIterator;
		static char**_overlay;
		//static vector<vector<char>> _overlay;
		int _numOfWalls;
		int _numOfFloors;
		GLfloat _x,_z;//translation coordinates
		static void constructQuadrant();

		/**
		 * @details [instantiates each char in 2d array
		 * and assigned the value of 'F' as floor to each char.
		 * calls void constructQuadrant()]
		 */
		void initialize();
		void initializeTestLevel();
		char W(float,float);//add wall to static data
		char F(float,float);//add tile to static data
		void G();//grass tile
		void D();//dirt tile

};

#endif
