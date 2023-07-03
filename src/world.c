#include "world.h"
#include "tile.h"

void generate_map(World* world)
{
	for (int y = 0; y < WORLD_HEIGHT * WORLD_WIDTH; ++y)
	{
		world->map_tiles[y] = TILE_WALK;
	}
}