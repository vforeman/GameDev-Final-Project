#ifndef LEVEL_H
#define LEVEL_H
/*
USAGE:
Level * lvl;
LevelFactory * lvlFactory;
lvl=lvlFactory->createLevel("Text");




*/
#include <string>
using namespace std;

namespace Level{

// abstract level
class LevelType{
public:
 void SetType(string s ){
  _type = s;
 };

protected:

private:
 string _type;

};

// Concrete Level
class FlatLevel : public LevelType{
private:

public:
 FlatLevel(){
  SetType("Flat");
 };


};

// Concrete Level
class TextLevel : public LevelType{
public:
 TextLevel(){
  SetType("Text");
 };

};

// Concrete Level
class RandomLevel : public LevelType{
public:
 RandomLevel(){
  SetType("Random");
 };


};

// Factory Method for Level construction
class LevelFactory{
public:
 LevelType *CreateButton(string levelType){
  if(levelType == "Text"){
   return new TextLevel;
  }
  if(levelType == "Flat"){
   return new FlatLevel;
  }
  if(levelType == "Random"){
   return new RandomLevel;
  }

 };


};





}
#endif
