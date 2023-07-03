#include "raygui.h"
#include "raylib.h"

enum GAME_TABS
{
	TAB_MAP,
	TAB_SETTLEMENT
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

const char* text[] =
{
		"Map",
		"Settlement",
		"Third",
		"Fourth"
};

void ingame_init()
{
	tab_game.rect = (Rectangle){10, 10, GetScreenWidth() - 10, 30};
	tab_game.text = text;
	tab_game.count = 4;
	tab_game.active = 0;
}

void ingame_draw()
{
	ClearBackground(RAYWHITE);
	GuiTabBar(tab_game.rect, tab_game.text, tab_game.count, &tab_game.active);

	switch(tab_game.active)
	{
		case TAB_MAP:
			DrawText("Map", 192, 168, 20, BLACK);
		default:
			break;
	}
}