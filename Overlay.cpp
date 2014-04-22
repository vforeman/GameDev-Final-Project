#include "src/Overlay.h"

unsigned int Overlay::OVERLAY_HEIGHT = 500;
unsigned int Overlay::OVERLAY_WIDTH = 500;

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
    Vector3f wallCenter = Vector3f(0,5,0);
    float height = (float)util::randomRange(6,12);
    float wall[] ={
         0.4f+_tx , height +_ty , 0.4f+_tz     ,-0.4f+_tx , height +_ty , 0.4f+_tz    ,-0.4f+_tx , height +_ty ,-0.4f+_tz    , 0.4f+_tx , height +_ty ,-0.4f+_tz,  //0123top
         0.4f+_tx , height +_ty , 0.4f+_tz     ,-0.4f+_tx , height +_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    , 0.4f+_tx , 0.2f+_ty , 0.4f+_tz , //0145north
         0.4f+_tx , height +_ty , 0.4f+_tz     , 0.4f+_tx , height +_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty , 0.4f+_tz,  //0365east
         0.4f+_tx , height +_ty ,-0.4f+_tz     ,-0.4f+_tx , height +_ty ,-0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz,  //3276south
        -0.4f+_tx , height +_ty ,-0.4f+_tz     ,-0.4f+_tx , height +_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz,  //2147west
         0.4f+_tx , 0.2f+_ty , 0.4f+_tz     ,-0.4f+_tx , 0.2f+_ty , 0.4f+_tz    ,-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz    , 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz  //5476bot
    };
    for (int c = 0; c< 72; c+=3){
        n=Vector3f(wall[c],wall[c+1],wall[c+2])-wallCenter;
        n.normalize();
        _staticNormals.push_back(n.x);      _staticNormals.push_back(n.y);      _staticNormals.push_back(n.z);
    }
    _staticVertices.insert( _staticVertices.end() , wall , wall + sizeof(wall)/sizeof(GLfloat));
    _staticIndex.insert(_staticIndex.end(),wall_index, wall_index+sizeof(wall_index)/sizeof(GLuint));
    _staticColors.insert(_staticColors.end(), wall_colors, wall_colors + sizeof(wall_colors)/sizeof(GLfloat));

    float treeTop[] ={
         height/2.0f + _tx , height+1.0f +_ty , height/2.0f + _tz     ,-height/2.0f + _tx , height+1.0f +_ty , height/2.0f + _tz    ,-height/2.0f + _tx , height+1.0f +_ty ,-height/2.0f + _tz    , height/2.0f + _tx , height+1.0f +_ty ,-height/2.0f + _tz,  //0123top
         height/2.0f + _tx , height+1.0f +_ty , height/2.0f + _tz     ,-height/2.0f + _tx , height+1.0f +_ty , height/2.0f + _tz    ,-height/2.0f + _tx , height +_ty , height/2.0f + _tz    , height/2.0f + _tx , height +_ty , height/2.0f + _tz , //height/2.05 n orth
         height/2.0f + _tx , height+1.0f +_ty , height/2.0f + _tz     , height/2.0f + _tx , height+1.0f +_ty ,-height/2.0f + _tz    , height/2.0f + _tx , height +_ty ,-height/2.0f + _tz    , height/2.0f + _tx , height +_ty , height/2.0f + _tz,  //0365east
         height/2.0f + _tx , height+1.0f +_ty ,-height/2.0f + _tz     ,-height/2.0f + _tx , height+1.0f +_ty ,-height/2.0f + _tz    ,-height/2.0f + _tx , height +_ty ,-height/2.0f + _tz    , height/2.0f + _tx , height +_ty ,-height/2.0f + _tz,  //3276south
        -height/2.0f + _tx , height+1.0f +_ty ,-height/2.0f + _tz     ,-height/2.0f + _tx , height+1.0f +_ty , height/2.0f + _tz    ,-height/2.0f + _tx , height +_ty , height/2.0f + _tz    ,-height/2.0f + _tx , height +_ty ,-height/2.0f + _tz,  //height/2.07 w est
         height/2.0f + _tx , height +_ty , height/2.0f + _tz     ,-height/2.0f + _tx , height +_ty , height/2.0f + _tz    ,-height/2.0f + _tx , height +_ty ,-height/2.0f + _tz    , height/2.0f + _tx , height +_ty ,-height/2.0f + _tz  //5476bot
    };
    for (int c = 0; c< 72; c+=3){
        n=Vector3f(treeTop[c],treeTop[c+1],treeTop[c+2])-wallCenter;
        n.normalize();
        _staticNormals.push_back(n.x);      _staticNormals.push_back(n.y);      _staticNormals.push_back(n.z);
    }
    _staticVertices.insert( _staticVertices.end() , treeTop , treeTop + sizeof(treeTop)/sizeof(GLfloat));
    _staticIndex.insert(_staticIndex.end(),treeTop_index, treeTop_index+sizeof(treeTop_index)/sizeof(GLuint));
    _staticColors.insert(_staticColors.end(), treeTop_colors, treeTop_colors + sizeof(treeTop_colors)/sizeof(GLfloat));
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
    (util::randomRange(1,100)%100 == 45)
        ? D()
        : G();
    ++_numOfFloors;
    return 'F';
}
void Overlay::G()
{
    _staticColors.insert(_staticColors.end(),tile_grass,tile_grass + sizeof(tile_grass)/sizeof(GLfloat));
}
void Overlay::D()
{
    _staticColors.insert(_staticColors.end(),tile_dirt,tile_dirt + sizeof(tile_dirt)/sizeof(GLfloat));
/*    if(_staticColors.size() > 2)
    {
        if(util::coinToss())
        {
            _staticColors.erase(_staticColors.end()-1);
            _staticColors.insert(_staticColors.end(),tile_dirt,tile_dirt + sizeof(tile_dirt)/sizeof(GLfloat));
        }
    }*/
}

Vector3f translate(Vector3f trans);
bool Overlay::isObstacle(Vector3f pos)
{
    Vector3f check = translate(pos);
    if(check.x < 0 || check.z < 0 || check.x >= (float)Overlay::OVERLAY_WIDTH || check.z >= (float)Overlay::OVERLAY_HEIGHT)
        return true;
    return _overlay[(int)check.x][(int)check.z] == 'W';
}
bool Overlay::isObstacle(int x, int z)
{
    Vector3f check = translate(Vector3f(float(x), 0.0f, float(z)));
    if(check.x < 0 || check.z < 0 || check.x >= (float)Overlay::OVERLAY_WIDTH || check.z >= (float)Overlay::OVERLAY_HEIGHT)
        return true;

    return _overlay[check.x][check.z] == 'W';
    
}
bool Overlay::isObstacle(int x, int y, int z)
{
    return Overlay::isObstacle(x, z);
}


/*TODO
 * FIGURE OUT A TRANSLATION SYSTEM IF RANJAY OR VICTOR DOESN'T DO IT FIRST
 *
 *
 * */
Vector3f adjust(Vector3f);    //Adjust for Overlay geometry
Vector3f translate(Vector3f trans)
{
    Vector3f val = adjust(trans);

    return val;
}

Vector3f adjust(Vector3f val)
{
    float adjX = (float)Overlay::OVERLAY_WIDTH/2;
    float adjZ = (float)Overlay::OVERLAY_HEIGHT/2;
    
    if((val.x == 0.0f || val.x == -0.0f) && (val.z == 0.0f || val.z == -0.0f))
        return Vector3f(49.0f, 0.0f, 49.0f);
    if(val.x >= 0 && val.z >= 0)    //1st
        return Vector3f(val.x, 0.0f, val.z);
    if(val.x <=0 && val.z >= 0)    //2nd
        return Vector3f(std::fabs(adjX+val.x), 0.0f, val.z);
    if (val.x <= 0 && val.z <= 0)  //3rd
        return Vector3f(std::fabs(adjX+val.x), 0.0f, std::fabs(adjZ+val.z)); 
    if (val.x >= 0 && val.z <= 0)  //4th
        return Vector3f(val.x, 0.0f, std::fabs(adjZ+val.z));

    return val=Vector3f(1000.0f, 0.0f, 1000.0f);
}

/*
    if(val.x >= 0 && val.z >= 0)    //1st
        return Vector3f(adjX+val.x, 0.0f, adjZ+val.z); 
    if(val.x <=0 && val.z >= 0)    //2nd
        return Vector3f(std::fabs(adjX-val.x), 0.0f, adjZ+val.z);
    if (val.x <= 0 && val.z <= 0)  //3rd
        return Vector3f(std::fabs(adjX-val.x), 0.0f, std::fabs(adjZ-val.z));
    if (val.x >= 0 && val.z <= 0)  //4th
        return Vector3f(adjX+val.x, 0.0f, std::fabs(adjZ-val.z));
*/
