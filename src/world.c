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

	//TEMP(Fix): just so it's not all floor
	world->map_tiles[1][3] = TILE_FOREST;
	world->map_tiles[2][3] = TILE_FOREST;
	world->map_tiles[3][3] = TILE_FOREST;
	world->map_tiles[4][3] = TILE_FOREST;
	world->map_tiles[5][3] = TILE_FOREST;

}

unsigned int get_tile(World* world, int x, int y)
{
	return world->map_tiles[y][x];
}
