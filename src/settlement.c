#include "settlement.h"
#include "citizen.h"
#include "world.h"
#include "raylib.h"


Settlement settlement_generate()
{
	Settlement new_settlement;

	new_settlement.population = GetRandomValue(1, 10);

	for (int i = 0; i < new_settlement.population; ++i)
	{
		new_settlement.citizens[i] = citizen_generate();
	}

	new_settlement.location.x  = GetRandomValue(1, WORLD_WIDTH - 2);
	new_settlement.location.y  = GetRandomValue(1, WORLD_HEIGHT - 2);


	//TEMP(Fix):
	new_settlement.citizens[0] = citizen_generate();
	new_settlement.citizens[0].type = CIT_GATHERER;


	new_settlement.citizens[1] = citizen_generate();
	new_settlement.citizens[1].type = CIT_GATHERER;

	new_settlement.citizens[3] = citizen_generate();
	new_settlement.citizens[3].type = CIT_GATHERER;

	new_settlement.wood = 0;
	new_settlement.food = 0;

	return new_settlement;
}

void settlement_tick(Settlement *self)
{
	self->prod_wood = 0;
	self->prod_food = 0;

	for (int i = 0; i < SET_MAX_CITIZENS; ++i)
	{
		if (self->citizens[i].type == CIT_GATHERER) 
		{
			self->prod_wood += 1;
			self->prod_food += 1;
		}
	}

	self->wood += self->prod_wood;
	self->food += self->prod_food;
}