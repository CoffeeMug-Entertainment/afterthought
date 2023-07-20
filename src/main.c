#include "menu.h"
#include "ingame.h"
#include "rsrc/font_SpaceMono.h"

#include "raylib.h"

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

enum GAME_STATE
{
	GSTATE_INVALID = 0,
	GSTATE_MAINMENU = 1,
	GSTATE_ONMAP
};

int current_state;
void (*draw_current)();
void (*tick_current)();

void nop(void){}

void change_game_state(unsigned int new_state)
{
	current_state = new_state;

	switch(current_state)
	{
		case GSTATE_MAINMENU:
			menu_init();
			draw_current = menu_draw;
			tick_current = nop;
			break;
		case GSTATE_ONMAP:
			ingame_init();
			draw_current = ingame_draw;
			tick_current = ingame_tick;
		case GSTATE_INVALID:
		default:
			break;
	}
}

Texture2D char_sheet;

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	InitWindow(1024, 576, "Afterthought");
	SetTargetFPS(60);

	change_game_state(GSTATE_MAINMENU);
	SetRandomSeed((unsigned int )time(NULL));

	Font_SpaceMono = LoadFont_SpaceMono();
	float last_tick_time;

	char_sheet = LoadTexture("./assets/spritesheet.png");

	while (!WindowShouldClose()) 
	{
		last_tick_time += GetFrameTime();
		if(last_tick_time < 1.0f/10.0f)
		{
			tick_current();
			last_tick_time = 0.0f;
		}

		BeginDrawing();
		{
			draw_current();
		}
		EndDrawing();
	}

	UnloadTexture(char_sheet);

	CloseWindow();
	return 0;
}
