#include "entity.h"
#include "fix_string.h"
#include "world.h"

#include "raylib.h"

void george_tick(Entity *self)
{
	if(self->pos.x == self->target_pos.x && self->pos.y == self->target_pos.y)
	{
		self->target_pos.x = GetRandomValue(0, WORLD_WIDTH - 1);
		self->target_pos.y = GetRandomValue(0, WORLD_HEIGHT - 1);
	}
}

void george_init(Entity *self)
{
	self->pos.x = GetRandomValue(0, WORLD_WIDTH - 1);
	self->pos.y = GetRandomValue(0, WORLD_HEIGHT - 1);

	self->target_pos.x = GetRandomValue(0, WORLD_WIDTH -1);
	self->target_pos.y = GetRandomValue(0, WORLD_HEIGHT -1 );

	self->name = cstring_to_fix_string("George");
	self->spritesheet_pos = (Vector2){1, 1};

	self->flags |= EF_MOVABLE;

	self->init = george_init;
	self->tick = george_tick;
}
