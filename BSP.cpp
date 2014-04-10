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
		{return false;}
	lateralCut = util::coinToss();
	if((_width > _height)&&(_width/_height >= 0.05))
		{lateralCut = false;}
	else if((_height > _width)&&(_height/_width >= 0.05))
		{lateralCut = true;}
 int tooSmall = (lateralCut ? _height:_width) - MIN_LEAF_SIZE;
 if(tooSmall <= MIN_LEAF_SIZE)
 	{return false;}
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

/**
 * @brief [Partition Tree Constructor]
 * @details [Initialize root Leaf of tree as well
 * as the leafList "_leaves"]
 */

/**************************************************************/

PartitionTree::PartitionTree()
{
		std::clog << "PartitionTree::PartitionTree()\n";
		//init root rect
	_root = new Leaf(MAPWIDTH,MAPHEIGHT,0,0);
	//add root to the list
	_leaves.push_back(*_root);////////////
	build();
	roomify(_root);
}


/**************************************************************/

/**
 * @brief [generate Partition Tree]
 * @details [Generate Tree by subdiving Leaves until
 * base leaves are sized between MIN and MAX sizes]
 */
void PartitionTree::build()
{std::clog << "PartitionTree::build()\n";
	_splitsLeft = true;
	while(_splitsLeft)
	{
		_splitsLeft = false;
		for( Leaf& helper : _leaves)
		{
			if((helper._left==NULL)&&(helper._right==NULL))
			{
				if((helper._width > Leaf::MAX_LEAF_SIZE)||(helper._height > Leaf::MIN_LEAF_SIZE))
				{
					if(helper.split())
					{
						_leaves.push_back(*helper._left);
						_leaves.push_back(*helper._right);
						_splitsLeft = true;
					}
				}
			}
		}
	}
}
/**
 * @brief [populate Partition Tree]
 * @details [traverse the tree to reach the base leaves that
 * we created last in the build() method. Those leaves are all inbetween
 *  the MIN and MAX sizes]
 *
 * @param  [Leaf::Leaf *]
 */
void PartitionTree::roomify(Leaf * helper)
{std::clog << "void PartitionTree::roomify(Leaf * helper)\n";
	if((helper->_left!=NULL)||(helper->_right!=NULL))
	{
		if(helper->_left!=NULL)
		{std::clog << "roomify(helper->_left)\n";
			roomify(helper->_left);
		}
		if(helper->_right!=NULL)
		{std::clog << "roomify(helper->_right);\n";
			roomify(helper->_right);
		}
	}
	else
	{
		//add helper leaf to roomlist vertex vector

		int rm[] ={util::randomRange(3,helper->_width-2),
			util::randomRange(3,helper->_height-2),
			util::randomRange(1,helper->_width-helper->_x-1),
			util::randomRange(1,helper->_height-helper->_y-1)
		};
		/*roomlist->push_back({helper->_x,-2,helper->_y});
		roomlist->push_back(helper->_x,-2,helper->_y+helper->_width);
		roomlist->push_back(helper->_x+helper->_height,-2,helper->_y+helper->_width);
		roomlist->push_back(helper->_x+helper->_height,-2,helper->_y)
*/
	}
}















}
