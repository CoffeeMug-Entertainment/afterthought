#ifndef AT_WORLD_H
#define AT_WORLD_H 1

#define WORLD_WIDTH 25
#define WORLD_HEIGHT 25

struct world_s
{
	char* name;
	unsigned int map_tiles[WORLD_HEIGHT][WORLD_WIDTH];
};

typedef struct world_s World;

void generate_map(World* world);

unsigned int get_tile(World* world, int x, int y);

#endif