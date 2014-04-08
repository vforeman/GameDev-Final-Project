#include "LevelFactory.h"
namespace level{

/**************************************************************/

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

/**************************************************************/
/**
 * @brief [Partition Tree Constructor]
 * @details [Initialize root Leaf of tree as well
 * as the leafList "_leaves"]
 */
PartitionTree::PartitionTree()
{
 _root = new Leaf(0,0,MAPWIDTH,MAPHEIGHT);
 _leaves.push_back(_root);
 build();
 roomify(_root);
}
/**
 * @brief [generate Partition Tree]
 * @details [Generate Tree by subdiving Leaves until
 * base leaves are sized between MIN and MAX sizes]
 */
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
/**
 * @brief [populate Partition Tree]
 * @details [traverse the tree to reach the base leaves that
 * we created last in the build() method. Those leaves are all inbetween
 *  the MIN and MAX sizes]
 *
 * @param  [Leaf::Leaf *]
 */
void PartitionTree::roomify(Leaf * helper)
{
 if((helper->_left!=NULL)||(helper->_right!=NULL))
 {
  if(helper->_left!=NULL)
  {
   roomify(helper->_left);
  }
  if(helper->_right!=NULL)
  {
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
  helper->_room=geo::Rectangle(rm[0],rm[1],rm[2], rm[3]);
 }
}
/**************************************************************/

LevelContainer * LevelContainer::_instance = NULL;
bool LevelContainer::_instanceFlag = false;
extern DATA LevelContainer::_data;

LevelContainer::LevelContainer(){}

LevelContainer::~LevelContainer()
{
 _instanceFlag = false;
}

LevelContainer * LevelContainer::get()
{
 if(_instance == NULL )
 {
  _instance = new LevelContainer();
  _instanceFlag = true;
  return _instance;
 }
 else
 {
  return _instance;
 }
}


//TODO: this should really be done by the renderer
/*void LevelContainer::drawLevel()
{

 glPushMatrix();
  glColor3f(0,1,1);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, );
  glDrawArrays(GL_QUADS, 0, 4);
  glDisableClientState(GL_VERTEX_ARRAY);
 glPopMatrix();

}*/

/**************************************************************/

FlatLevel::FlatLevel(string levelType)
{/*
 LevelContainer::_data._ptree = new ParitionTree();
 LevelContainer::_data._x =0;
 LevelContainer::_data._y =0;
 LevelContainer::_data._maxObjects = 10;
 LevelContainer::_data._numObjects = 1;
 LevelContainer::_data._numTiles = ( 8 * 8 );
 LevelContainer::_data._type = levelType;
 LevelContainer::_data._objs = new physics::PhysicsEntity[LevelContainer::_data._numObjects];*/
}
void FlatLevel::draw(){}

TextLevel::TextLevel(){}
TextLevel::TextLevel(string levelType)
{
/* LevelContainer::_data._type = levelType;*/
}
void TextLevel::draw(){}

RandomLevel::RandomLevel(){}
RandomLevel::RandomLevel(string levelType)
{
 LevelContainer::_data._ptree = new PartitionTree();
 LevelContainer::_data._mesh =0;
 LevelContainer::_data._maxObjects = 10;
 LevelContainer::_data._numObjects = 1;
 LevelContainer::_data._numTiles = ( 8 * 8 );
 LevelContainer::_data._type = levelType;
 LevelContainer::_data._objs = new physics::PhysicsEntity[LevelContainer::_data._numObjects];
}
void RandomLevel::draw(){
 glPushMatrix();
  float colors[]={1,0,0,1,0,0,1,0,0,1,1,0,1,1,0,1,0,0,1,0,0,1,0,0};
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  //3 values per vertex, glfloat type, 0 stride, pointer to array

  glColorPointer(1,GL_FLOAT,0,colors);
  glVertexPointer(3,GL_FLOAT,0,LevelContainer::_data._mesh);


  //QUADS primitive, 0 start index, 4 elements in the array
  glDrawArrays(GL_QUADS,0,4);

  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);

 glPopMatrix();
}

/**************************************************************/

/*void genTiles()
{
 LevelContainer::_data._tiles = new geo::Rectangle * [8];
 for(int m = 0; m < 8; ++m)
 {
  LevelContainer::_data._tiles[m] = new geo::Rectangle[8];
 }
}*/

void createLevel( string levelType)
{
/* if(levelType == "Text")
 {
  TextLevel(levelType);
 }
 else */if(levelType == "Random")
 {
  RandomLevel(levelType);
 }
/* else if(levelType == "Flat")
 {
  FlatLevel(levelType);
 }*/
/* genTiles();
*/ /*genMesh()*/;
}

void printMesh()
{
 for(int n = 0; n < 12; ++n){
  cout<<LevelContainer::_data._mesh[n]<<endl;
 }
}


}//namespace level
