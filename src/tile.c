#include "tile.h"

Tile tiles[] =
{
	{' ', __INT_MAX__},
	{'.', 1},
	{'#', __INT_MAX__}

};


char get_tile_symbol(unsigned int type)
{
	return tiles[type].symbol;
}
