#include "world.h"
#include "tile.h"
#include "citizen.h"
#include "settlement.h"
#include "drawing.h"

#include "raygui.h"
#include "raylib.h"

#include <string.h>

enum GAME_TABS
{
	TAB_MAP,
	TAB_SETTLEMENT,
	TAB_CITIZENS
};

struct at_tabbar_s
{
	Rectangle rect;
	const char **text;
	int count;
	int active;
};

typedef struct at_tabbar_s TabBar;

TabBar tab_game;

World game_world;
Settlement player_settlement;
char map_str[WORLD_WIDTH * WORLD_HEIGHT + WORLD_HEIGHT];

const char* text[] =
{
		"Map",
		"Settlement",
		"Citizens",
		"Fourth"
};


void ingame_init()
{
	tab_game.rect = (Rectangle){10, 10, GetScreenWidth() - 10, 30};
	tab_game.text = text;
	tab_game.count = 4;
	tab_game.active = 0;

	player_settlement = settlement_generate();
	strcpy(player_settlement.name, "Your Settlement");

	generate_map(&game_world);
}

extern Font Font_SpaceMono;

void map_draw()
{
	for(int y = 0; y < WORLD_HEIGHT; ++y)
	{
		for(int x = 0; x < WORLD_WIDTH; ++x)
		{
			Vector2 sheet_tile = tiles[get_tile(&game_world, x, y)].spritesheet_pos;
			DrawChar(sheet_tile, (Vector2){x, y}, RAYWHITE);
		}
	}

	DrawChar((Vector2){0, 1}, player_settlement.location, YELLOW);
}

void settlement_draw()
{
	DrawText(player_settlement.name, 10, 42, 18, RAYWHITE);
}

void citizens_draw()
{
	
}

void ingame_draw()
{
	ClearBackground(DARKGRAY);
	GuiTabBar(tab_game.rect, tab_game.text, tab_game.count, &tab_game.active);

	switch(tab_game.active)
	{
		case TAB_MAP:
			map_draw();
			break;
		case TAB_SETTLEMENT:
			settlement_draw();
			break;
		case TAB_CITIZENS:
			citizens_draw();
		default:
			break;
	}
}
