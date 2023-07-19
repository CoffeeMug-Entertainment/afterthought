#include "world.h"
#include "tile.h"

void generate_map(World* world)
{
	for (int y = 0; y < WORLD_HEIGHT; ++y)
	{
		for (int x = 0; x < WORLD_WIDTH; ++x)
		{
			world->map_tiles[y][x] = TILE_WALK;
		}
	}
}

unsigned int get_tile(World* world, int x, int y)
{
	return world->map_tiles[y][x];
}
