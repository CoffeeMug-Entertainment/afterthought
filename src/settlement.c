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

	new_settlement.location = GetRandomValue(10, WORLD_WIDTH * WORLD_HEIGHT - 10);

	return new_settlement;
}