#ifndef TILES_H
#define	TILES_H
namespace level{
#define GRASS {0,1,0,0.6}
#define DIRT {0.651,0.50,0.392,0.6}
#define WALL {0.933,0.231,0.231,0.6}
#define WINDOW {1,1,0,0.2}

typedef enum {
	grass,
	dirt,
	wall,
	window
}TileType;

class Tiles{
public:
	static TileType TILES;
};


} //namespace level
#endif
