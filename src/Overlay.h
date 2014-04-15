#ifndef OVERLAY_H
#define OVERLAY_H
#include "Vmath.h"
#include "Util.h"
#include <vector>
#include "Assets.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;
using namespace util;
// typedef GLfloat Mesh[6][4][3];
// typedef GLfloat ** Mesh;

// void destructMesh(Mesh * );
// Mesh::~Mesh();

class Overlay
{
	public:
		Overlay();//calls initialize function
		~Overlay();
		static bool isObstacle(Vector3f);
        static bool isObstacle(int, int, int);
		static bool isObstacle(int, int);
		void constructOverlay();

		static vector<vector<char>> _overlay;
		static vector<GLfloat> _staticVertices;
	private:
		int _numOfWalls;
		int _numOfFloors;
		GLfloat _tx,_ty,_tz;//translation coordinates
		static unsigned int OVERLAY_HEIGHT;
		static unsigned int OVERLAY_WIDTH;
		/**
		 * @details [instantiates each char in 2d array
		 * and assigned the value of 'F' as floor to each char.
		 * calls void constructQuadrant()]
		 */
		void initialize();
		void pushFloor();
		void pushWall();
		char W();
		char F();
};

#endif
