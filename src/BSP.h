/**
 * Implementation of Binary Space Partitioning
 */
#ifndef BSP_H
#define BSP_H
#include "Util.h"
#include "Geometry.h"
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
namespace level{

class Leaf
{
public:
	/**
	 * @brief [Overloaded Leaf Constructor]
	 * @details [long description]
	 * @return [new Leaf of size 0 or specified size]
	 */
	Leaf(int width = 0, int height = 0, int x =0, int y =0);
	~Leaf();
	bool split();
	int _width;
	int _height;
	float _x;
	int _y;
	Leaf * _left;
	Leaf * _right;
 geo::Rectangle _room;
	static const int MIN_LEAF_SIZE = 6;
	static const int MAX_LEAF_SIZE = 20;
};

/**************************************************************/

class PartitionTree
{
public:
	PartitionTree();
	void build();
	void roomify(Leaf*);
	const int MAPWIDTH = 50;
	const int MAPHEIGHT = 50;
 vector<Leaf>  _leaves;
 Leaf * _root;
 bool _splitsLeft;

};

/**************************************************************/




}//namespace level
#endif
