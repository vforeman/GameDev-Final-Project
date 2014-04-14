#ifndef GENERATOR_H
#define GENERATOR_H
#include <stdint.h>
#include <stdint.h>
#include <stdlib.h>
#include <cmath>
#include <ctime>

#define COLUMNS 20
void constructQuadrant(char[][COLUMNS], unsigned int, unsigned int);

class Generator
{
    public:
        static int Random();
        static float Randomf();
    private:
        static uint32_t Rand();
};





#endif
