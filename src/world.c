#include "world.h"

Tile tiles[] =
{
	{TILE_NOTHING, (Vector2){0, 0}, __INT_MAX__},
	{TILE_FLOOR,   (Vector2){1, 0}, 1},
	{TILE_WALL,    (Vector2){2, 0}, __INT_MAX__},
	{TILE_FOREST,  (Vector2){3, 0}, 2},
};

void generate_map(World* world)
{
	for (int y = 0; y < WORLD_HEIGHT; ++y)
	{
		for (int x = 0; x < WORLD_WIDTH; ++x)
		{
			world->map_tiles[y][x] = TILE_FLOOR;
		}
	}

	//TEMP(Fix): just so it's not all floor
	world->map_tiles[1][3] = TILE_FOREST;
	world->map_tiles[2][3] = TILE_FOREST;
	world->map_tiles[3][3] = TILE_FOREST;
	world->map_tiles[4][3] = TILE_FOREST;
	world->map_tiles[5][3] = TILE_FOREST;

}

unsigned int get_tile_idx(World* world, int x, int y)
{
	return world->map_tiles[y][x];
}


Tile *get_tile(World* world, int x, int y)
{
	return &tiles[get_tile_idx(world, x, y)];
}

