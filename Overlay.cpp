#include "src/Overlay.h"

unsigned int Overlay::OVERLAY_HEIGHT = 100;//z
unsigned int Overlay::OVERLAY_WIDTH = 100;//x
float Overlay::OVERLAY_HF = (float)Overlay::OVERLAY_HEIGHT;//z
float Overlay::OVERLAY_WF = (float)Overlay::OVERLAY_WIDTH;//x
int Overlay::OVERLAY_HI = (int)Overlay::OVERLAY_HF;//z
int Overlay::OVERLAY_WI = (int)Overlay::OVERLAY_WF;//x

char** Overlay::_overlay = new char*[Overlay::OVERLAY_WI];

//vector<vector<char>> Overlay::_overlay (Overlay::OVERLAY_HEIGHT);
vector<GLfloat> Overlay::_staticVertices;
vector<GLfloat> Overlay::_staticNormals;
vector<GLfloat> Overlay::_staticColors;
vector<GLshort> Overlay::_staticTexCoords;
vector<GLuint> Overlay::_staticIndex;

Overlay::Overlay(){
    for(int  c =0; c< Overlay::OVERLAY_WI; ++c ){
       Overlay::_overlay[c] = new char[Overlay::OVERLAY_HI];
    }
    _numOfWalls = 0;
    _numOfFloors = 0;
    //NW corner is structural ~ origin,(0,0) and trans_values
    //are adjusted for offset from the world origin

    initialize();

}

Overlay::~Overlay()
{}

//initiate and populate char obstacle map
void Overlay::initialize(){
/*--------------BOUNDARY OF THE MAP-----------------*/
    _x = -(Overlay::OVERLAY_WF/2.0);
    _z = -(Overlay::OVERLAY_HF/2.0);
    for(int u = 0; u < Overlay::OVERLAY_WI; ++u){
            Overlay::_overlay[0][u] = W(_x,_z);
            Overlay::_overlay[Overlay::OVERLAY_HI-1][u] = W(_x,_z+Overlay::OVERLAY_HF-1);
            ++_x; 
    }_x = 1.0 -(Overlay::OVERLAY_WI/2.0);
    for(int i =1; i < Overlay::OVERLAY_HI-1; ++i){
        Overlay::_overlay[i][0] = W(_x,_z);
        Overlay::_overlay[i][Overlay::OVERLAY_WI-1] = W(Overlay::OVERLAY_WF-1,_z); 
    }
/*--------------RANDOM OBSTACLES-----------------*/
    _x = 1.0 -(Overlay::OVERLAY_WF/2.0);
    _z = 1.0-(Overlay::OVERLAY_HF/2.0);
    for( int u = 1; u < Overlay::OVERLAY_WI-1; ++u){
        for(int i = 1; i < Overlay::OVERLAY_HI-1 ; ++i){             
           //Todo::reward contiguous wall behavior,shame lonely pillar
            Overlay::_overlay[i][u] =  (randomRange(1,100)%100 == 90) ? W(_x,_z) : F(_x,_z);
            cout<<isObstacle(_x,_z);
            // cout<<'('<<_tx<<','<<_tz<<')';
            ++_x;           
        }
        cout<<endl;
        _x = 1.0-(Overlay::OVERLAY_WI/2.0);
        ++_z;
    }
}
char Overlay::W(float _tx, float _tz){
    float _ty = -3.0f;
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
    cout<<'W';
    return 'W';
}
char Overlay::F(float _tx, float _tz){
    float _ty = -3.0f;
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
    cout<<'F';
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
bool Overlay::isObstacle(float x, float z)
{
    if(x < -(Overlay::OVERLAY_WF/2.0)) x = -(Overlay::OVERLAY_WF/2.0)-1;
    if(z < -(Overlay::OVERLAY_HF/2.0)) z = -(Overlay::OVERLAY_HF/2.0)-1;
    if(x >= (Overlay::OVERLAY_WF/2.0)) x = (Overlay::OVERLAY_WF/2.0)-1;
    if(z >= (Overlay::OVERLAY_HF/2.0)) z = (Overlay::OVERLAY_HF/2.0)-1;
    /*Vector3f check = translate(Vector3f(float(x), 0.0f, float(z)));
    if(check.x < 0 || check.z < 0 || check.x >= (float)Overlay::OVERLAY_WIDTH || check.z >= (float)Overlay::OVERLAY_HEIGHT)
        return true;

    return _overlay[check.x][check.z] == 'W';*/
    x+=(Overlay::OVERLAY_WF/2);
    z+=(Overlay::OVERLAY_HF/2);

    if((int)x < 0 || (int)z < 0)
        return true;

    return _overlay[(int)x][(int)z] == 'W';
}
Vector3f translate(Vector3f trans);
bool Overlay::isObstacle(Vector3f pos)
{
/*    Vector3f check = translate(pos);
    if(check.x < 0 || check.z < 0 || check.x >= (float)Overlay::OVERLAY_WIDTH || check.z >= (float)Overlay::OVERLAY_HEIGHT)
        return true;
    return _overlay[(int)check.x][(int)check.z] == 'W';*/
    return isObstacle(pos.x,pos.z);
}

bool Overlay::isObstacle(float x, float y, float z)
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
        return Vector3f(adjX-1.0f, 0.0f, adjZ-1.0f);
    if(val.x >= 0 && val.z >= 0)    //1st
        return Vector3f(adjX+val.x, 0.0f, adjZ+val.z);
    if(val.x <=0 && val.z >= 0)    //2nd
        return Vector3f(adjX+val.x, 0.0f, adjZ+val.z);
    if (val.x <= 0 && val.z <= 0)  //3rd
        return Vector3f(adjX+val.x, 0.0f, adjZ+val.z); 
    if (val.x >= 0 && val.z <= 0)  //4th
        return Vector3f(adjX+val.x, 0.0f, adjZ+val.z);

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
