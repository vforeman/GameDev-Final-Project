 #include "LevelFactory.h"
namespace level{

/**************************************************************/

LevelContainer * LevelContainer::_instance = NULL;
bool LevelContainer::_instanceFlag = false;


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
void LevelContainer::genFlat()
{






}
/**************************************************************/
FlatLevel::FlatLevel(){}
FlatLevel::FlatLevel(std::string ){}
void FlatLevel::draw(){}
FlatLevel::~FlatLevel(){}

TextLevel::TextLevel(){}
TextLevel::TextLevel(std::string ){}
void TextLevel::draw(){}
TextLevel::~TextLevel(){}

RandomLevel::RandomLevel(){}
RandomLevel::RandomLevel(std::string )
{}
void RandomLevel::draw(){
 glPushMatrix();
  float colors[]={1,0,0,1,0,0,1,0,0,1,1,0,1,1,0,1,0,0,1,0,0,1,0,0};
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  //3 values per vertex, glfloat type, 0 stride, pointer to array
  glColorPointer(1,GL_FLOAT,0,colors);
  glVertexPointer(3,GL_FLOAT,0,0);
  //QUADS primitive, 0 start index, 4 elements in the array
  glDrawArrays(GL_QUADS,0,4);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
 glPopMatrix();
}
RandomLevel::~RandomLevel(){}

/**************************************************************/



/*void printMesh()
{
 for(int n = 0; n < 12; ++n){
  cout<<LevelContainer::get()->_mesh[n]<<endl;
 }
}*/


}//namespace level
