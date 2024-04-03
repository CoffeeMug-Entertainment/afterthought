#ifndef AT_PATHFINDING_H
#define AT_PATHFINDING_H 

#include "world.h"
#include "raylib.h"

Vector2 path_move_dir(Vector2 start, Vector2 end);
Vector2 find_nearest_of_type(World *world, unsigned int tile_type, Vector2 start_pos);

#endif