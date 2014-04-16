#ifndef OVERLAY_H
#define OVERLAY_H

#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include "Vmath.h"
#include "Util.h"
#include "Assets.h"

using namespace std;
using namespace util;

class Overlay
{
	public:
		Overlay();//calls initialize function
		~Overlay();
		static bool isObstacle(Vector3f);
  static bool isObstacle(int, int, int);
		static bool isObstacle(int, int);
		static vector<GLfloat> _staticVertices;
		static vector<GLfloat> _staticNormals;
		static vector<GLfloat> _staticColors;
		static vector<GLshort> _staticTexCoords;

	private:
		static vector<vector<char>> _overlay;
		int _numOfWalls;
		int _numOfFloors;
		GLfloat _tx,_ty,_tz;//translation coordinates
		static unsigned int OVERLAY_HEIGHT;
		static unsigned int OVERLAY_WIDTH;
		static void constructQuadrant();

		/**
		 * @details [instantiates each char in 2d array
		 * and assigned the value of 'F' as floor to each char.
		 * calls void constructQuadrant()]
		 */
		void initialize();
		void init();
		char W();//add wall to static data
		char F();//add tile to static data
  void initializeTestLevel();
};

#endif
