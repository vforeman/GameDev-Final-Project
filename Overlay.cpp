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
    _tx = -((float)Overlay::OVERLAY_WIDTH)/2.0;
    _ty = -3.0f;//constant floor level
    _tz = -((float)Overlay::OVERLAY_HEIGHT)/2.0;
    // initializeTestLevel();
    initialize();

}

Overlay::~Overlay()
{}

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
    _staticNormals.insert(_staticNormals.end(),wall_normals, wall_normals + sizeof(GLfloat));
    _staticColors.insert(_staticColors.end(), wall_colors, wall_colors + sizeof(GLfloat));
    _staticTexCoords.insert(_staticTexCoords.end(), wall_tex_coords, wall_tex_coords + sizeof(GLshort));
    _numOfWalls++;
    return 'W';
}
char Overlay::F(){
    GLfloat tile[] ={
         0.4f+_tx , 0.2f+_ty , 0.4f+_tz     ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz,  //top
    };//didn't think the floor needed to be so 3D
    _staticVertices.insert( _staticVertices.end() , tile , tile + sizeof(tile)/sizeof(GLfloat));
    _staticNormals.insert(_staticNormals.end(),tile_normals,tile_normals + sizeof(GLfloat));
    _staticColors.insert(_staticColors.end(),tile_colors,tile_colors + sizeof(GLfloat));
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



