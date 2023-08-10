#include "ui.h"
#include "raygui.h"
#include "raylib.h"
#include <stdlib.h>

void change_game_state(unsigned int new_state);

#define TOGGLE_WIDTH_RATIO 100 / 1024
#define TOGGLE_HEIGHT_RATIO 50 / 576

Toggle new_game;
Toggle toggle_settings;
Toggle toggle_quit;

//Settings Window
Window win_settings;

void menu_init()
{
	win_settings.rect = (Rectangle){120, 10, 800, 500};
	win_settings.title = "Settings";

	int ypos = 0.4 * GetScreenHeight();
	int screen_y = GetScreenHeight();

	int toggle_width = GetScreenWidth() * TOGGLE_WIDTH_RATIO;
	int toggle_height = GetScreenHeight() * TOGGLE_HEIGHT_RATIO;
	
	new_game.rect = (Rectangle){10, ypos, toggle_width, toggle_height};
	new_game.text = "New Game";

	ypos += 0.1 * screen_y;

	toggle_settings.rect = (Rectangle){10, ypos, toggle_width, toggle_height};
	toggle_settings.text = "Settings";

	ypos += 0.1 * screen_y;

	toggle_quit.rect = (Rectangle){10, ypos, toggle_width, toggle_height};
	toggle_quit.text = "Quit";
}

void menu_draw()
{
	ClearBackground(RAYWHITE);
	if(draw_toggle(&new_game))
	{
		change_game_state(2);
	}

	if(draw_toggle(&toggle_settings))
	{
		win_settings.active = true;
	}

	if(draw_toggle(&toggle_quit))
	{
		CloseWindow();
		exit(0); //TODO(Fix): don't do this, lmao
	}

	if(win_settings.active)
	{
		bool shouldClose = draw_window(&win_settings);
		DrawText("Resolution", win_settings.rect.x + 5, win_settings.rect.y + 30, 10, LIGHTGRAY);

		if(shouldClose)
		{
			win_settings.active = !win_settings.active;
		}
	}
}