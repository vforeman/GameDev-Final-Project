#include "BSP.h"
namespace level{


Leaf::Leaf(int width, int height, int x, int y)
:_width(width),_height(height),_x(x),_y(y)
{}
Leaf::~Leaf()
{}
bool Leaf::split()
{
	bool lateralCut;
	if((_left!=NULL)||(_right!=NULL))
		return false;

	lateralCut = util::coinToss();
	if((_width > _height)&&(_width/_height >= 0.05))
		lateralCut = false;
	else if((_height > _width)&&(_height/_width >= 0.05))
		lateralCut = true;
 int tooSmall = (lateralCut ? _height:_width) - MIN_LEAF_SIZE;
 if(tooSmall <= MIN_LEAF_SIZE)
 	return false;
 int cutLocation = util::randomRange(MIN_LEAF_SIZE,tooSmall);
 if(lateralCut)
 {
 	_left = new Leaf(_x,_y,_width,cutLocation);
 	_right = new Leaf(_x+cutLocation,_y,_width-cutLocation,_height);
 }
 else
 {
 	_left = new Leaf(_x,_y,cutLocation,_height);
 	_right = new Leaf(_x+cutLocation,_y,_width-cutLocation,_height);
 }

 return true;
}

/**************************************************************/

PartitionTree::PartitionTree()
{
	_root = new Leaf(0,0,MAPWIDTH,MAPHEIGHT);
}

void PartitionTree::build()
{
	_splitsLeft = true;
	while(_splitsLeft)
	{
		_splitsLeft = false;
		for( auto helper : _leaves)
		{
			if((helper->_left==NULL)&&(helper->_right==NULL))
			{
				if((helper->_width > Leaf::MAX_LEAF_SIZE)||(helper->_height > Leaf::MIN_LEAF_SIZE))
				{
					if(helper->split())
					{
						_leaves.push_back(helper->_left);
						_leaves.push_back(helper->_right);
						_splitsLeft = true;
					}
				}
			}
		}
	}
}



















}//namespace level
