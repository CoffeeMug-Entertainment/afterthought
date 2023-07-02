#include "raylib.h"
#include "menu.h"
#include <stdio.h> 

enum GAME_STATE
{
	GSTATE_INVALID = 0,
	GSTATE_MAINMENU = 1,
	GSTATE_ONMAP
};

int current_state;
void (*draw_current)();

void change_game_state(unsigned int new_state)
{
	current_state = new_state;

	switch(current_state)
	{
		case GSTATE_MAINMENU:
			menu_init();
			draw_current = &menu_draw;
			break;
		case GSTATE_INVALID:
		default:
			break;
	}
}

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	InitWindow(1024, 576, "Afterthought");
	SetTargetFPS(60);

	change_game_state(GSTATE_MAINMENU);

	while (!WindowShouldClose()) 
	{
		BeginDrawing();
		{
			draw_current();
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}