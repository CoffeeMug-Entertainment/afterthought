#ifndef AT_WORLD_H
#define AT_WORLD_H 1

#define WORLD_WIDTH 5
#define WORLD_HEIGHT 5

struct world_s
{
	char* name;
	unsigned int map_tiles[WORLD_WIDTH * WORLD_HEIGHT];
};

typedef struct world_s World;

void generate_map(World* world);

#endif