/**@Dependencies:
*	PRIMITIVE
**/
#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <cstdint>
using namespace std;
namespace util{
static bool init = false;


inline uint32_t xorshift()
{

 static uint32_t _x = 123456789;
 static uint32_t _y = 362436069;
 static uint32_t _z = 521288629;
 static uint32_t _w = 88675123;
 uint32_t _t;

 _t = _x ^ (_x << 11);
 _x = _y;
 _y = _z;
 _z = _w;
 return _w = _w ^ (((_w >> 19) ^ _t) ^ (_t>>8));
}

inline bool coinToss()
{
	if(!init)
	{
		srand(time(NULL));
		init=true;
	}
	return rand()%2;
}

inline int randomRange(int a, int z)
{
	if(!init)
	{
		srand(time(NULL));
		init=true;
	}
	cout<<a<<"->"<<z<<endl;
	int high = ((a < z )? z : a);
	int low = ((a < z )? a : z);

	cout<<rand()<<" "<<rand()<<endl;
	return (rand()%(high-low)) + low;

}


/*inline long unsigned int * randomBinaryMap(int row=0, int col=0)
:const _row(length),_col(col)
{


}
*/



}//namespace util
#endif
