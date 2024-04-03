#ifndef AT_SETTLEMENT_H
#define AT_SETTLEMENT_H 1

#include "citizen.h"
#include "raylib.h"

#define SET_MAX_CITIZENS 150

enum
{
	SET_NONE = 0,
	SET_PLAYER = 1,
	SET_ALLY = 2,
	SET_ENEMY = 3
};

struct at_settlement_s
{
	char name[25];
	//TODO(Fix): dynamic container of citizens
	Citizen citizens[SET_MAX_CITIZENS];
	unsigned int population;

	Vector2 location;

	unsigned int alignment;

	// Inventory
	unsigned int wood;
	unsigned int food;

	//Production
	int prod_wood;
	int prod_food;
};

typedef struct at_settlement_s Settlement;

Settlement settlement_generate();
void settlement_tick(Settlement *self);

extern Settlement *player_settlement;

#endif