#include "LevelFactory.h"
namespace level{

LevelContainer LevelFactory::_levelContainer ={
  "Main Static Level Container"
};

LevelFactory::LevelFactory(){}
LevelFactory::~LevelFactory(){}
LevelFactory * LevelFactory::get(){}
LevelContainer * LevelFactory::getLevel(string lvl){}


}
