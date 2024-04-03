#include "entity.h"
#include "raylib.h"
#include "world.h"
#include "pathfinding.h"
#include <settlement.h>
#include <stdio.h>

void gatherer_tick(Entity *self)
{
	if(self->pos.x == self->target_pos.x && self->pos.y == self->target_pos.y)
	{
		
	}
}

void gatherer_init(Entity *self)
{
	Vector2 temp = find_nearest_of_type(&game_world, TILE_FOREST, self->pos);

	printf("My target is at {%f, %f}", temp.x, temp.y);

	if (temp.x != -1)
	{
		self->target_pos = temp;
	}

	self->name = cstring_to_fix_string("Gatherer");
	self->spritesheet_pos = (Vector2){1, 1};

	self->flags |= EF_MOVABLE;

	self->init = gatherer_init;
	self->tick = gatherer_tick;
}