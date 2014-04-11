#include "LevelFactory.h"
namespace level{

LevelContainer LevelFactory::_levelContainer ={
  "Main Static Level Container"
};
LevelFactory * LevelFactory::_instance = NULL;
bool LevelFactory::_instanceFlag = false;

LevelFactory::LevelFactory()
{
  std::clog << "Constructing Level Factory\n";
}
LevelFactory::~LevelFactory()
{
  std::clog << "Destructing Level Factory\n";
}
LevelFactory * LevelFactory::get()
{
  std::clog << "Accessing Level Factory Instance\n";
}
LevelContainer * LevelFactory::getLevel(string lvl)
{
 std::clog << "Accessing Level Container Instance\n";
}


}
