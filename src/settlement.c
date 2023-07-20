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

	return new_settlement;
}