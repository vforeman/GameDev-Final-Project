#include "LevelFactory.h"
namespace level{

LevelContainer LevelFactory::_levelContainer ={
	"Singleton Level Mesh",
	{}
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
  _instanceFlag = false;
  assert(_instanceFlag == false);
 }
LevelFactory * LevelFactory::get()
{
  std::clog << "Accessing Level Factory Instance\n";
  if(!_instanceFlag)
  {
  	assert(!_instanceFlag);
  	if(_instance == NULL)
  	{
  		assert(_instance == NULL);
  		std::clog << "Instantiating Level Factory\n";
  		_instance = new LevelFactory();
  		_instanceFlag = true;
  		return _instance;
  	}
  }
  else
 	{
 		assert(_instance != NULL);
 		return _instance;
 	}
}
LevelContainer * LevelFactory::getLevel(string lvl)
{
 std::clog << "Accessing Level Container Instance\n";
 //tell the render to draw flat map already in resources
 if(lvl == "Flat")
 {

 }
 return &_levelContainer;
}


}
