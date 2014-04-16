#ifndef ASSETS_H
#define ASSETS_H
#include <GL/gl.h>
#include <GL/glu.h>
#define green {0,1,0,1}
#define cyan {0,1,1,1}
#define yellow {1,1,0,1}
#define red {1,0,0,1}
#define blue {0,0,1,1}
#define magenta {1,0,1,1}



const GLfloat checker[] = {
    0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f
};
const GLfloat colors[6][4][4] ={
 {green,green,green,green},
 {cyan,cyan,cyan,cyan},
 {yellow,yellow,yellow,yellow},
 {red,red,red,red},
 {blue,blue,blue,blue},
 {magenta,magenta,magenta,magenta},
};
const GLfloat tilecolor[4][4]={
	green,cyan,yellow,blue
};
const GLfloat tileall[] ={
 // top
 // top
 -1.0f, 1.0f,-1.0f, 0.0f, 0.0f,
 -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
  1.0f, 1.0f,-1.0f, 1.0f, 0.0f,
  1.0f, 1.0f,-1.0f, 1.0f, 0.0f,
 -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
};
const GLfloat tilenormal[4][3]={
 { 1, 0, 0} , { 1, 0, 0} , { 1, 0, 0} , { 1, 0, 0}
};
const GLfloat cube[] = {
 // X 		Y 					Z 				U	 			V
 // bottom
 -1.0f,-1.0f,-1.0f, 0.0f, 0.0f,
  1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
 -1.0f,-1.0f, 1.0f, 0.0f, 1.0f,
  1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
  1.0f,-1.0f, 1.0f, 1.0f, 1.0f,
 -1.0f,-1.0f, 1.0f, 0.0f, 1.0f,

 // top
 -1.0f, 1.0f,-1.0f, 0.0f, 0.0f,
 -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
  1.0f, 1.0f,-1.0f, 1.0f, 0.0f,
  1.0f, 1.0f,-1.0f, 1.0f, 0.0f,
 -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,

 // front
 -1.0f,-1.0f, 1.0f, 1.0f, 0.0f,
  1.0f,-1.0f, 1.0f, 0.0f, 0.0f,
 -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
  1.0f,-1.0f, 1.0f, 0.0f, 0.0f,
  1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
 -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,

 // back
 -1.0f,-1.0f,-1.0f, 0.0f, 0.0f,
 -1.0f, 1.0f,-1.0f, 0.0f, 1.0f,
  1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
  1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
 -1.0f, 1.0f,-1.0f, 0.0f, 1.0f,
  1.0f, 1.0f,-1.0f, 1.0f, 1.0f,

 // left
 -1.0f,-1.0f, 1.0f, 0.0f, 1.0f,
 -1.0f, 1.0f,-1.0f, 1.0f, 0.0f,
 -1.0f,-1.0f,-1.0f, 0.0f, 0.0f,
 -1.0f,-1.0f, 1.0f, 0.0f, 1.0f,
 -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
 -1.0f, 1.0f,-1.0f, 1.0f, 0.0f,

 // right
  1.0f,-1.0f, 1.0f, 1.0f, 1.0f,
  1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
  1.0f, 1.0f,-1.0f, 0.0f, 0.0f,
  1.0f,-1.0f, 1.0f, 1.0f, 1.0f,
  1.0f, 1.0f,-1.0f, 0.0f, 0.0f,
  1.0f, 1.0f, 1.0f, 0.0f, 1.0f
};

//Vertex array for faces of a cube
static const GLfloat tileface[24][3] ={
  { .9, .9, .9}, { .9,0.7, .9}, { .9,0.7,-.9}, { .9, .9,-.9} ,//east
  { .9, .9,-.9}, { .9,0.7,-.9}, {-.9,0.7,-.9}, {-.9, .9,-.9} ,//south
  {-.9, .9,-.9}, {-.9,0.7,-.9}, {-.9,0.7, .9}, {-.9, .9, .9} ,//west
  {-.9, .9, .9}, {-.9,0.7, .9}, { .9,0.7, .9}, { .9, .9, .9} ,//north
  {-.9, .9,-.9}, {-.9, .9, .9}, { .9, .9, .9}, { .9, .9,-.9} ,//top
  { .9,0.7, .9}, { .9,0.7,-.9}, {-.9,0.7,-.9}, {-.9,0.7, .9}//bot
};

//Vertex array for normals of the cube
static const GLfloat normals[6][4][3] ={
 { { 0, 1, 0} , { 0, 1, 0} , { 0, 1, 0} , { 0, 1, 0} },//top
 { { 0, 0, 1} , { 0, 0, 1} , { 0, 0, 1} , { 0, 0, 1} },//north
 { { 1, 0, 0} , { 1, 0, 0} , { 1, 0, 0} , { 1, 0, 0} },//east
 { { 0, 0,-1} , { 0, 0,-1} , { 0, 0,-1} , { 0, 0,-1} },//soutn
 { {-1, 0, 0} , {-1, 0, 0} , {-1, 0, 0} , {-1, 0, 0} },//west
 { { 0,-1, 0} , { 0,-1, 0} , { 0,-1, 0} , { 0,-1, 0} }//bottom

};
const GLfloat tile_normals[] = {
        0,1,0,  0,1,0,  0,1,0, 0,1,0
    };
const GLfloat tile_colors[] = {
        0.54, 0.0, 0.1,0.3,//Burgandy
        0.54, 0.0, 0.1,0.3,//Burgandy
        0.54, 0.0, 0.1,0.3,//Burgandy
        0.54, 0.0, 0.1,0.3,//Burgandy
  };
const GLshort tile_tex_coords[] = {
        0,0,    1,0,    1,1,    0,1
    };

const GLfloat wall_normals[] = {
        0,1,0,  0,1,0,  0,1,0, 0,1,0,//top
        0,0,1,  0,0,1,  0,0,1,  0,0,1,//north^
        1,0,0, 1,0,0, 1,0,0, 1,0,0,//east>
        0,0,-1,  0,0,-1,  0,0,-1,  0,0,-1,//south\/
        -1,0,0, -1,0,0, -1,0,0, -1,0,0,//west<
        0,-1,0,  0,-1,0,  0,-1,0, 0,-1,0//bottom
    };
const GLfloat wall_colors[] = {
        0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,
        0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,
        0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,
        0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,
        0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,
        0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3,  0,0.54, 0.1,0.3
    };
const GLshort wall_tex_coords[] = {
        0,0,    1,0,    1,1,    0,1
    };


//original 3d floor tile vertex data
/*
GLfloat tile[] ={
         0.4f+_tx , 0.2f+_ty , 0.4f+_tz     ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz,  //top
         0.4f+_tx , 0.2f+_ty , 0.4f+_tz     ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.0f+_ty , 0.4f+_tz    , 0.4f+_tx , 0.0f+_ty , 0.4f+_tz , //north
         0.4f+_tx , 0.2f+_ty , 0.4f+_tz     , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.0f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.0f+_ty , 0.4f+_tz,  //east
         0.4f+_tx , 0.2f+_ty ,-0.4f+_tz     ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    ,-0.4f+_tx , 0.0f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.0f+_ty ,-0.4f+_tz,  //south
        -0.4f+_tx , 0.2f+_ty ,-0.4f+_tz     ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.0f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.0f+_ty ,-0.4f+_tz,  //west
         0.4f+_tx , 0.0f+_ty , 0.4f+_tz     ,-0.4f+_tx , 0.0f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.0f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.0f+_ty ,-0.4f+_tz,  //bot
    };//didn't think the floor needed to be so 3D

*/

#endif
