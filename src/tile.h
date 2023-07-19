#ifndef AT_TILE_H
#define AT_TILE_H 1

enum TILE_TYPE
{
	TILE_NOTHING = 0,
	TILE_WALK,
	TILE_WALL
};

struct tile_s
{
	char symbol;
	int pass_difficulty;
};

typedef struct tile_s Tile;

char get_tile_symbol(unsigned int type);

extern Tile tiles[];
#endif