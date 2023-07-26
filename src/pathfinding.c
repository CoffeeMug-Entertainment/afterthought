#include "raylib.h"
#include "raymath.h"

Vector2 path_move_dir(Vector2 start, Vector2 end)
{
	Vector2 move_dir = Vector2Subtract(end, start);
	move_dir.x = (move_dir.x > 0) - (move_dir.x < 0);
	move_dir.y = (move_dir.y > 0) - (move_dir.y < 0);

	return move_dir;
}