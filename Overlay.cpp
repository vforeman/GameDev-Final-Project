#include "Overlay.h"
unsigned int Overlay::OVERLAY_HEIGHT = 200;
unsigned int Overlay::OVERLAY_WIDTH = 200;
typedef GLfloat  Mesh[6][4][3];
static Mesh tile;

vector<vector<char>> Overlay::_overlay (Overlay::OVERLAY_HEIGHT);
vector<Mesh> Overlay::_staticVertices;

// void destructMesh(Mesh * m){
//     for()
// }
// Mesh::~Mesh(){

// }

Overlay::Overlay(){
    _numOfWalls = 0;
    _numOfFloors = 0;
    //NW corner is structural ~ origin,(0,0) and trans_values
    //are adjusted for offset from the world origin
    _tx = -((float)Overlay::OVERLAY_WIDTH)/2;
    _ty = -3.0f;//constant floor level
    _tz = ((float)Overlay::OVERLAY_HEIGHT)/2;

    initialize();
    cout<<typeid(_staticVertices).name()<<endl;
    cout<<typeid(wall_vertices).name()<<endl;
    cout<<typeid(Mesh).name()<<endl;
}
Overlay::~Overlay(){}
//initiale and populate char obstacle map
void Overlay::initialize(){
    //rows of the map; _tx
    for(vector<char> &s : _overlay){
        s.resize(Overlay::OVERLAY_WIDTH );
        //columns of the map; _tz
        for(char &c : s){
            c =  (randomRange(1,10)%10 == 9) ? W() : F();
        }
        _tx == (GLfloat)Overlay::OVERLAY_WIDTH ? _tx = 0 : ++_tx;
        _tx == (GLfloat)Overlay::OVERLAY_HEIGHT ? _tz = 0 : ++_tz;
    }
    constructOverlay();
}
char Overlay::W(){

    // for( float (&vertices)[3] : *wall_vertices){
    //     for(float (&coords) : vertices){
    //         cout<<coords<<endl;
    //         staticVertices.emplace_back(coords);
    //     }
    // }
    cout<<'\n';
    _numOfWalls++;
    return 'W';
}
char Overlay::F(){
    Mesh tile ={

        {{ 0.4f+_tx , 0.2f+_ty , 0.4f+_tz } , {-0.4f+_tx , 0.2f+_ty , 0.4f+_tz } ,{-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz } ,{ 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz }} ,//top
        {{ 0.4f+_tx , 0.2f+_ty , 0.4f+_tz } , {-0.4f+_tx , 0.2f+_ty , 0.4f+_tz } ,{-0.4f+_tx , 0.0f+_ty , 0.4f+_tz } ,{ 0.4f+_tx , 0.0f+_ty , 0.4f+_tz }} ,//north
        {{ 0.4f+_tx , 0.2f+_ty , 0.4f+_tz } , { 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz } ,{ 0.4f+_tx , 0.0f+_ty ,-0.4f+_tz } ,{ 0.4f+_tx , 0.0f+_ty , 0.4f+_tz }} ,//east
        {{ 0.4f+_tx , 0.2f+_ty ,-0.4f+_tz } , {-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz } ,{-0.4f+_tx , 0.0f+_ty ,-0.4f+_tz } ,{ 0.4f+_tx , 0.0f+_ty ,-0.4f+_tz }} ,//south
        {{-0.4f+_tx , 0.2f+_ty ,-0.4f+_tz } , {-0.4f+_tx , 0.2f+_ty , 0.4f+_tz } ,{-0.4f+_tx , 0.0f+_ty , 0.4f+_tz } ,{-0.4f+_tx , 0.0f+_ty ,-0.4f+_tz }} ,//west
        {{ 0.4f+_tx , 0.0f+_ty , 0.4f+_tz } , {-0.4f+_tx , 0.0f+_ty , 0.4f+_tz } ,{-0.4f+_tx , 0.0f+_ty ,-0.4f+_tz } ,{ 0.4f+_tx , 0.0f+_ty ,-0.4f+_tz }}  //bot
    };
    _staticVertices.emplace_back(&tile);



    ++_numOfFloors;
    return 'F';
}
void Overlay::constructOverlay(){

}


// Overlay::Overlay()
// {
// 	initialize();
// };
// Overlay::~Overlay()
// {
//     for(int c = 0; c< Overlay::OVERLAY_HEIGHT;++c)
//     {
//         delete[] _overlay[c];
//     }
//     delete[] _overlay;
// };

// /*char Overlay::getObstacle(float radius,Vector3<float> pos)
// {
//     //A lot of variables for checking radius of sphere
//     //For loop crashed the game
//     char val = 'F';
//     float x = pos.x;
//     float z = pos.z;
//     unsigned int i = 0;
//     unsigned int j = 0;

//             i = std::abs((int)roundf(x))/10;
//             j = std::abs((int)roundf(z))/10;

//             if(i >= 10 || j >= 10 || i < 0 || j < 0)
//                 return 'W';

//             if(x >= 0.0f && z >= 0.0f)
//                if(_overlay[i][j] == 'W')
//                     return 'W';

//             if(x <= 0.0f && z >=0.0f)
//                if(_overlay[i][j] == 'W')
//                     return 'W';

//             if(x <= 0.0f && z <= 0.0f)
//                if(_overlay[i][j] == 'W')
//                     return 'W';

//             if(x >= 0.0f && z <= 0.0f)
//                if(_overlay[i][j] == 'W')
//                     return 'W';

//     return val;
// } */

bool Overlay::isObstacle(Vector3f pos)
{
	return _overlay[(int)pos.x][(int)pos.z] == 'W';
}
bool Overlay::isObstacle(int x, int z)
{
    return _overlay[x][z] == 'W';
}


// void Overlay::initialize()
// {
//     for(int c = 0; c< Overlay::OVERLAY_HEIGHT;++c)
//     {
//         _overlay[c] = new char[Overlay::OVERLAY_HEIGHT];
//     }
// 	for(unsigned int i = 0; i < Overlay::OVERLAY_HEIGHT; ++i)
//         for(unsigned int j = 0; j < Overlay::OVERLAY_WIDTH; ++j)
//             _overlay[i][j] = 'F';
//         //!!this for loop does absolutely nothing
// 	 /*for(unsigned int i = 0; i < 5; ++i)
//         xorshift(); // Random function from util class instead of generator, Random function was a intermediate call to the Rand() function*/

// 	constructQuadrant();


// };

// void Overlay::constructQuadrant()
// {
//     int wallcount =0;
//     float x=0;
//     float z =0;
//     for(unsigned int i = 0; i < Overlay::OVERLAY_HEIGHT; ++i)
//     {
//         for(unsigned int j = 0; j < Overlay::OVERLAY_WIDTH; ++j)
//         {
//             //gives you ten percent walls
//             if(randomRange(0,100) % 100>= 90)
//             {
//                 ++wallcount;
//                 cout<<wallcount<<"walls"<<endl;
//                 _overlay[i][j] = 'W';
//                 _wallPoints.push_back(Vector3f(0,0,0));
//             }
//            else//push back floor tile verts
//            {
//             for(const float * f1 : tileface)
//             {
//                 float top[]={}
//                 _wallPoints.push_back((x+f1[0]));//x
//                 _wallPoints.push_back(f1[1]);//y
//                 _wallPoints.push_back((z+f1[2]));//z
//                     // clog <<*f1<<','<<f1[1]<<','<<f1[2]<<'\n';

//             }
//             // _wallPoints.push_back(tileface);
//            }
//         }
//     }

// };

