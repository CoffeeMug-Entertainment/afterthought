#include "world.h"
#include "tile.h"
#include "citizen.h"
#include "settlement.h"

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

//UGLY(Fix): I tried to be smart about this, but the strings defeated me. In the end, this garbage was written
void generate_map_string()
{
	char tempLine[WORLD_WIDTH + 2]; //2 extra: 1 for newline, 1 for null-term

	for(int y = 0; y < WORLD_HEIGHT; ++y)
	{
		for(int x = 0; x < WORLD_WIDTH; ++x)
		{
			int i = x + y * WORLD_WIDTH;
			tempLine[x] = tiles[game_world.map_tiles[i]].symbol;
		}

		tempLine[WORLD_WIDTH] = '\n';
		tempLine[WORLD_WIDTH + 1] = '\0';
		strcat(map_str, tempLine);
	}

	map_str[player_settlement.location] = '@';
}

void ingame_init()
{
	tab_game.rect = (Rectangle){10, 10, GetScreenWidth() - 10, 30};
	tab_game.text = text;
	tab_game.count = 4;
	tab_game.active = 0;

	player_settlement = settlement_generate();
	strcpy(player_settlement.name, "Your Settlement");

	generate_map(&game_world);
	generate_map_string();
}

extern Font Font_SpaceMono;

void map_draw()
{
	static Vector2 pos = (Vector2){10, 40};
	DrawTextEx(Font_SpaceMono, map_str, pos, 36, 0, BLACK);
}

void settlement_draw()
{
	DrawText(player_settlement.name, 10, 42, 18, BLACK);
}

void citizens_draw();

void ingame_draw()
{
	ClearBackground(RAYWHITE);
	GuiTabBar(tab_game.rect, tab_game.text, tab_game.count, &tab_game.active);

	switch(tab_game.active)
	{
		case TAB_MAP:
			map_draw();
			break;
		case TAB_SETTLEMENT:
			settlement_draw();
			break;
		default:
			break;
	}
}
