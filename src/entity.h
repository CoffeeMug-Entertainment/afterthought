#ifndef AT_ENTITY_H
#define AT_ENTITY_H

#include "raylib.h"

struct entity_s
{
	char name[10];
	Vector2 spritesheet_pos;

	Vector2 pos;
	Vector2 move_dir;
	Vector2 target_pos;

	void (*init)(struct entity_s *self);
	void (*tick)(struct entity_s *self);
};

typedef struct entity_s Entity;

#endif