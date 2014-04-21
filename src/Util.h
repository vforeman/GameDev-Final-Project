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
#include <typeinfo>
#include <random>

using namespace std;
namespace util{
static bool init = false;

inline bool coinToss(){
	if(!init){
		srand(time(NULL));
		init=true;
	}
	return rand()%2;
}

inline int randomRange(int a, int z){
	if(!init){
		srand(time(NULL));
		init=true;
	}
	int high = ((a < z )? z : a);
	int low = ((a < z )? a : z);

	return (rand()%(high-low)) + low;

}

/**
 * @brief [brief description]
 * @details [returns a char pointer to a random sequence of charaters of {length}
 *  consisting of characters {c1} and {c2}]
 *
 * @param int [length of char array to be returned]
 * @param c1 [one of 2 sequence characters]
 * @param c2 [other one of 2 sequence characters]
 * @return [char * [length]={[c1|c2]^*}]
 */
inline void randomCharSeq(char * s ,unsigned int length, char c1, char c2){
		if(!init){
		srand(time(NULL));
		init=true;
	}



	// char randSeq[length];
	// for(char & c : randSeq){
	// 	c = coinToss() ? c1 : c2;
	// }
	// s = randSeq;




}

/*inline long unsigned int * randomBinaryMap(int row=0, int col=0)
:const _row(length),_col(col)
{


}
*/



}//namespace util
#endif
