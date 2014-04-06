#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

namespace util{

uint32_t xorshift()
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
    return _w = _w & (_w >> 19) ^ _t ^ (_t>>8);
}



}
#endif
