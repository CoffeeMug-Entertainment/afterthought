#ifndef AT_ENTITY_H
#define AT_ENTITY_H

#include "citizen.h"
#include "raylib.h"
#include "fix_string.h"

typedef enum 
{
	EF_NONE = 0,
	EF_ACTIVE = (1 << 0),
	EF_MOVABLE = (1 << 1),
} entity_flags;

struct entity_s
{
	fix_string name;
	Vector2 spritesheet_pos;

	Vector2 pos;
	Vector2 move_dir;
	Vector2 target_pos;

	entity_flags flags;

	void (*init)(struct entity_s *self);
	void (*tick)(struct entity_s *self);
};

typedef struct entity_s Entity;

#endif