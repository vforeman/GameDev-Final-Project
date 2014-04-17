#include "src/Overlay.h"

unsigned int Overlay::OVERLAY_HEIGHT = 50;
unsigned int Overlay::OVERLAY_WIDTH = 50;

vector<vector<char>> Overlay::_overlay (Overlay::OVERLAY_HEIGHT);
vector<GLfloat> Overlay::_staticVertices;
vector<GLfloat> Overlay::_staticNormals;
vector<GLfloat> Overlay::_staticColors;
vector<GLshort> Overlay::_staticTexCoords;
vector<GLuint> Overlay::_staticIndex;

Overlay::Overlay(){
    _numOfWalls = 0;
    _numOfFloors = 0;
    //NW corner is structural ~ origin,(0,0) and trans_values
    //are adjusted for offset from the world origin
    _tx = -((float)Overlay::OVERLAY_WIDTH)/2.0;
    _ty = -3.0f;//constant floor level
    _tz =-((float)Overlay::OVERLAY_HEIGHT)/2.0;
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
    Vector3f n;
    Vector3f center = Vector3f(0,5,0);
    float wall[] ={
         0.4f+_tx , 10.0+_ty , 0.4f+_tz     ,-0.4f+_tx , 10.0+_ty , 0.4f+_tz    ,-0.4f+_tx , 10.0+_ty ,-0.4f+_tz    , 0.4f+_tx , 10.0+_ty ,-0.4f+_tz,  //0123top
         0.4f+_tx , 10.0f+_ty , 0.4f+_tz     ,-0.4f+_tx , 10.0f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    , 0.4f+_tx , 0.2f+_ty , 0.4f+_tz , //0145north
         0.4f+_tx , 10.0f+_ty , 0.4f+_tz     , 0.4f+_tx , 10.0f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty , 0.4f+_tz,  //0365east
         0.4f+_tx , 10.0f+_ty ,-0.4f+_tz     ,-0.4f+_tx , 10.0f+_ty ,-0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz,  //3276south
        -0.4f+_tx , 10.0f+_ty ,-0.4f+_tz     ,-0.4f+_tx , 10.0f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz,  //2147west
         0.4f+_tx , 0.2f+_ty , 0.4f+_tz     ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz  //5476bot
    };
    for (int c = 0; c< 72; c+=3){
        n=Vector3f(wall[c],wall[c+1],wall[c+2])-center;
        n.normalize();
        _staticNormals.push_back(n.x);      _staticNormals.push_back(n.y);      _staticNormals.push_back(n.z);
    }
    _staticVertices.insert( _staticVertices.end() , wall , wall + sizeof(wall)/sizeof(GLfloat));
    _staticIndex.insert(_staticIndex.end(),wall_index, wall_index+sizeof(wall_index)/sizeof(GLuint));
    _staticColors.insert(_staticColors.end(), wall_colors, wall_colors + sizeof(wall_colors)/sizeof(GLfloat));
    _numOfWalls++;
    return 'W';
}
char Overlay::F(){
    GLfloat tile[] ={
         0.4f+_tx , 0.2f+_ty , 0.4f+_tz     ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz  //top
    };//didn't think the floor needed to be so 3D
    _staticVertices.insert( _staticVertices.end() , tile , tile + sizeof(tile)/sizeof(GLfloat));
    _staticIndex.insert(_staticIndex.end(),tile_index, tile_index+sizeof(tile_index)/sizeof(GLuint));
    _staticNormals.insert(_staticNormals.end(),tile_normals,tile_normals + sizeof(tile_normals)/sizeof(GLfloat));
    _staticColors.insert(_staticColors.end(),tile_colors,tile_colors + sizeof(tile_colors)/sizeof(GLfloat));

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



