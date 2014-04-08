/**
 * Implementation of Binary Space Partitioning
 */
#ifndef BSP_H
#define BSP_H
#include "Util.h"
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
namespace level{

class Leaf
{
public:
	Leaf(int width = 0, int height = 0, int x =0, int y =0);
	~Leaf();
	bool split();
	int _width;
	int _height;
	int _x;
	int _y;
	Leaf * _left;
	Leaf * _right;
	static const int MIN_LEAF_SIZE = 6;
	static const int MAX_LEAF_SIZE = 20;
};

class PartitionTree
{
public:
	PartitionTree();
	void build();
	void drawLevel();
	const int MAPWIDTH = 50;
	const int MAPHEIGHT = 50;
 std::vector<Leaf*> _leaves;
 Leaf * _root;
 bool _splitsLeft;

};





}//namespace level
#endif
