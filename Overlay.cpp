#include "src/Overlay.h"

unsigned int Overlay::OVERLAY_HEIGHT = 25;
unsigned int Overlay::OVERLAY_WIDTH = 25;

vector<vector<char>> Overlay::_overlay (Overlay::OVERLAY_HEIGHT);
vector<GLfloat> Overlay::_staticVertices;
vector<GLfloat> Overlay::_staticNormals;
vector<GLfloat> Overlay::_staticColors;
vector<GLshort> Overlay::_staticTexCoords;

Overlay::Overlay(){
    _numOfWalls = 0;
    _numOfFloors = 0;
    //NW corner is structural ~ origin,(0,0) and trans_values
    //are adjusted for offset from the world origin
    _tx = -((float)Overlay::OVERLAY_WIDTH)/2;
    _ty = -3.0f;//constant floor level
    _tz = -((float)Overlay::OVERLAY_HEIGHT)/2;
    initialize();
}
Overlay::~Overlay(){}
//initiate and populate char obstacle map
void Overlay::initialize(){
    char connected = 'U';
    //rows of the map; _tx
    for(vector<char> &s : _overlay){
        s.resize(Overlay::OVERLAY_WIDTH );
        //columns of the map; _tz
        for(char &c : s){
            //Todo::reward contiguous wall behavior,
            //shame lonely pillar
            c =  (randomRange(1,100)%100 == 90) ? W() : F();
            connected = c;
            ++_tx;
        }
        _tx = -((float)Overlay::OVERLAY_HEIGHT)/2;
        ++_tz;
    }
}
char Overlay::W(){
    GLfloat wall[] ={
         0.4f+_tx , 0.2f+_ty , 0.4f+_tz     ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz,  //top
         0.4f+_tx , 10.0f+_ty , 0.4f+_tz     ,-0.4f+_tx , 10.0f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.0f+_ty , 0.4f+_tz    , 0.4f+_tx , 0.0f+_ty , 0.4f+_tz , //north
         0.4f+_tx , 10.0f+_ty , 0.4f+_tz     , 0.4f+_tx , 10.0f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.0f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.0f+_ty , 0.4f+_tz,  //east
         0.4f+_tx , 10.0f+_ty ,-0.4f+_tz     ,-0.4f+_tx , 10.0f+_ty ,-0.4f+_tz    ,-0.4f+_tx , 0.0f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.0f+_ty ,-0.4f+_tz,  //south
        -0.4f+_tx , 10.0f+_ty ,-0.4f+_tz     ,-0.4f+_tx , 10.0f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.0f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.0f+_ty ,-0.4f+_tz,  //west
         0.4f+_tx , 0.0f+_ty , 0.4f+_tz     ,-0.4f+_tx , 0.0f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.0f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.0f+_ty ,-0.4f+_tz,  //bot
    };
    _staticVertices.insert( _staticVertices.end() , wall , wall + sizeof(wall)/sizeof(GLfloat));
    GLfloat wall_normals[] = {
        0,1,0,  0,1,0,  0,1,0, 0,1,0,//top
        0,0,1,  0,0,1,  0,0,1,  0,0,1,//north^
        1,0,0, 1,0,0, 1,0,0, 1,0,0,//east>
        0,0,-1,  0,0,-1,  0,0,-1,  0,0,-1,//south\/
        -1,0,0, -1,0,0, -1,0,0, -1,0,0,//west<
        0,-1,0,  0,-1,0,  0,-1,0, 0,-1,0,//bottom
    };
    _staticNormals.insert(_staticNormals.end(),wall_normals, wall_normals + sizeof(GLfloat));
    GLfloat wall_colors[] = {
        0,0.54, 0.1/*,0.3*/
    };
    _staticColors.insert(_staticColors.end(), wall_colors, wall_colors + sizeof(GLfloat));
    GLshort wall_tex_coords[] = {
        0,0,    1,0,    1,1,    0,1
    };
    _staticTexCoords.insert(_staticTexCoords.end(), wall_tex_coords, wall_tex_coords + sizeof(GLshort));
    _numOfWalls++;
    return 'W';
}
char Overlay::F(){
    GLfloat tile[] ={
         0.4f+_tx , 0.2f+_ty , 0.4f+_tz     ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz,  //top
    };//didn't think the floor needed to be so 3D
    _staticVertices.insert( _staticVertices.end() , tile , tile + sizeof(tile)/sizeof(GLfloat));
    GLfloat tile_normals[] = {
        0,1,0,  0,1,0,  0,1,0, 0,1,0
    };
    _staticNormals.insert(_staticNormals.end(),tile_normals,tile_normals + sizeof(GLfloat));
    GLfloat tile_colors[] = {
        0.54, 0, 0.1/*,0.3*///Burgandy
    };
    _staticColors.insert(_staticColors.end(),tile_colors,tile_colors + sizeof(GLfloat));
     GLshort tile_tex_coords[] = {
        0,0,    1,0,    1,1,    0,1
    };
    _staticTexCoords.insert(_staticTexCoords.end(), tile_tex_coords, tile_tex_coords + sizeof(GLshort));

    ++_numOfFloors;
    return 'F';
}
bool Overlay::isObstacle(Vector3f pos)
{
	return _overlay[(int)pos.x][(int)pos.z] == 'W';
}
bool Overlay::isObstacle(int x, int z)
{
    return _overlay[x][z] == 'W';
}
bool Overlay::isObstacle(int x, int y, int z)
{
    return Overlay::isObstacle(x, z);
}


//Read from a two dimensional character array that is already created
//LEVEL_ONE AND LEVEL_TWO are levels of size 100x100 and 200x200
//src/levels.h has LEVEL_ONE and LEVEL_TWO
void Overlay::initializeTestLevel()
{
/*    for(unsigned int c = 0; c < Overlay::OVERLAY_HEIGHT; ++c)
        _overlay[c] = new char[Overlay::OVERLAY_HEIGHT];

    
    if(Overlay::OVERLAY_HEIGHT == 100)
        for(unsigned int i = 0; i < Overlay::OVERLAY_HEIGHT; ++i)
            for(unsigned int j = 0; j < Overlay::OVERLAY_WIDTH; ++j)
                _overlay[i][j] = LEVEL_ONE[i][j];
    else if(Overlay::OVERLAY_HEIGHT == 200)
        for(unsigned int i = 0; i < Overlay::OVERLAY_HEIGHT; ++i)
            for(unsigned int j = 0; j < Overlay::OVERLAY_WIDTH; ++j)
                _overlay[i][j] = LEVEL_TWO[i][j];
    else
        initialize();
*/
}
