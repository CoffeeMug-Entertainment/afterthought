#include "tile.h"
#include "raylib.h"

Tile tiles[] =
{
	{(Vector2){0, 0}, __INT_MAX__}, //TILE_NOTHING
	{(Vector2){1, 0}, 1}, 			//TILE_WALK
	{(Vector2){2, 0}, __INT_MAX__}, //TILE_WALL
	{(Vector2){3, 0}, 2}, 			//TILE_FOREST
};

