#include "entity.h"
#include "pathfinding.h"

#include "raymath.h"
#include <string.h>

void george_init(Entity *self)
{

}

#include <stdio.h>
void george_tick(Entity *self)
{
	//self->move_dir = path_move_dir(self->pos, self->target_pos);
	//self->pos = Vector2Add(self->pos, self->move_dir);
	//self->move_dir = Vector2Zero();
}

void spawn_george(Entity *self)
{
	strcpy(self->name, "George");
	self->spritesheet_pos = (Vector2){1, 1};

	self->init = george_init;
	self->tick = george_tick;
}