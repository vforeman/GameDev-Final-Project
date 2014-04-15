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


struct ModelAsset {
 GLuint vbo;
 GLuint vao;
 GLenum drawType;
 GLint drawStart;
 GLint drawCount;
 ModelAsset() :
	 vbo(0),
	 vao(0),
	 drawType(GL_TRIANGLES),
	 drawStart(0),
	 drawCount(0)
	{}
};
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

static const GLfloat floor_vertices[6][4][3]={
  {{},{},{},{}},//top
  {{},{},{},{}},//north
  {{},{},{},{}},//east
  {{},{},{},{}},//south
  {{},{},{},{}},//west
  {{},{},{},{}}//bottom
};
static const GLfloat wall_vertices[6][4][3]={
  {{},{},{},{}},//top
  {{},{},{},{}},//north
  {{},{},{},{}},//east
  {{},{},{},{}},//south
  {{},{},{},{}},//west
  {{},{},{},{}}//bottom
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

 { { 1, 0, 0} , { 1, 0, 0} , { 1, 0, 0} , { 1, 0, 0} },
 { { 0, 0,-1} , { 0, 0,-1} , { 0, 0,-1} , { 0, 0,-1} },
 { {-1, 0, 0} , {-1, 0, 0} , {-1, 0, 0} , {-1, 0, 0} },
 { { 0, 0, 1} , { 0, 0, 1} , { 0, 0, 1} , { 0, 0, 1} },
 { { 0, 1, 0} , { 0, 1, 0} , { 0, 1, 0} , { 0, 1, 0} },
 { { 0,-1, 0} , { 0,-1, 0} , { 0,-1, 0} , { 0,-1, 0} }

};
#endif
