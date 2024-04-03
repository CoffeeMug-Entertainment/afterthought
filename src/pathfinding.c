#include "world.h"

#include "raylib.h"
#include "raymath.h"

Vector2 path_move_dir(Vector2 start, Vector2 end)
{
	Vector2 move_dir = Vector2Subtract(end, start);
	move_dir.x = (move_dir.x > 0) - (move_dir.x < 0);
	move_dir.y = (move_dir.y > 0) - (move_dir.y < 0);

	return move_dir;
}

Vector2 find_nearest_of_type(World *world, unsigned int tile_type, Vector2 start_pos)
{
	Vector2 nearest = (Vector2){-1, -1};
	int total_steps = __INT_MAX__;

	for (int y = 0; y < WORLD_HEIGHT; y += 1)
	{
		for (int x = 0; x < WORLD_WIDTH; x += 1)
		{
			Tile *tile = get_tile(world, x, y);
			if(tile->type != tile_type) continue;

			#define MAX_STEP_COUNT 256
			bool arrived = false;
			int step_count = 0;
			Vector2 current_pos = start_pos;
			for(; step_count < MAX_STEP_COUNT; step_count += 1)
			{
				Vector2 move_dir = path_move_dir(current_pos, (Vector2){x, y});
				current_pos = Vector2Add(current_pos, move_dir);
				move_dir = Vector2Zero();

				if(current_pos.x == x && current_pos.y == y)
				{
					arrived = true;
					break;
				}
			}

			if(step_count <= total_steps)
			{
				if(Vector2Distance(start_pos, (Vector2){x, y}) < Vector2Distance(start_pos, nearest))
				{
					nearest.x = x;
					nearest.y = y;
					total_steps = step_count;
				}
			}
		}
	}

	return nearest;
}