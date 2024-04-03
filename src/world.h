#ifndef AT_WORLD_H
#define AT_WORLD_H 1

#include "raylib.h"

#define WORLD_WIDTH 20
#define WORLD_HEIGHT 16

enum TILE_TYPE
{
	TILE_NOTHING = 0,
	TILE_FLOOR,
	TILE_WALL,
	TILE_FOREST
};

struct tile_s
{
	unsigned int type;
	Vector2 spritesheet_pos;
	int pass_difficulty;
};
typedef struct tile_s Tile;

struct world_s
{
	char* name;
	unsigned int map_tiles[WORLD_HEIGHT][WORLD_WIDTH];
};
extern Tile tiles[];

typedef struct world_s World;

void generate_map(World* world);

unsigned int get_tile_idx(World* world, int x, int y);

Tile *get_tile(World* world, int x, int y);

extern World game_world;

#endif