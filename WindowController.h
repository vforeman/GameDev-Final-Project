#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H
#include <SDL/SDL.h>
#include <stdio.h>
namespace window{

 /// Opens, Maintains, and Shutsdown a SINGLE instance
 class Window
 {
 public:
 	//PUBLIC methods
  static Window * getInstance();
  ~Window();
  void open( void );
  void close( void );
  void resize( int, int );
  void resize( char * );

 private:
  // PRIVATE attributes
  static Window * _instance;
  static bool _instanceFlag;

  // PRIVATE methods
  Window();
 };




}//namespace window
#endif //WINDOWCONTROLLER_H
