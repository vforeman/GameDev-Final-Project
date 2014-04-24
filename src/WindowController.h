/**@Dependencies:
* PRIMITIVE
**/
#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H
#include <SDL/SDL.h>
/*#include <stdio.h>
#include "SDL_mixer.h"*/
namespace window{

 /// Opens, Maintains, and Shutsdown a SINGLE instance
 class Window
 {
    public:
 	//PUBLIC methods
    static Window& get();
    static SDL_Surface * _screen;
    void open( void );
    void close( void );
    /*void resize( int, int );
    void resize( char * );*/

    private:
        Window();
        Window(const Window&);
        Window& operator=(const Window&);
 };




}//namespace window
#endif //WINDOWCONTROLLER_H
