#include "raygui.h"
#include "raylib.h"
#include <stdlib.h>

#define TOGGLE_WIDTH 100
#define TOGGLE_HEIGHT 50

struct at_toggle_s
{
	Rectangle rect;
	const char* text;
	bool active;
};

typedef struct at_toggle_s Toggle;

Toggle new_game;
Toggle toggle_settings;
Toggle toggle_quit;

bool draw_toggle(Toggle* toggle)
{
	return GuiToggle(toggle->rect, toggle->text, toggle->active);
}

void menu_init()
{
	int ypos = 200;
	int screen_y = GetScreenHeight();

	new_game.rect = (Rectangle){10, ypos, TOGGLE_WIDTH, TOGGLE_HEIGHT};
	new_game.text = "New Game";

	ypos += 0.1 * screen_y;

	toggle_settings.rect = (Rectangle){10, ypos, TOGGLE_WIDTH, TOGGLE_HEIGHT};
	toggle_settings.text = "Settings";

	ypos += 0.1 * screen_y;

	toggle_quit.rect = (Rectangle){10, ypos, TOGGLE_WIDTH, TOGGLE_HEIGHT};
	toggle_quit.text = "Quit";
}

void menu_draw()
{
	ClearBackground(RAYWHITE);
	if(draw_toggle(&new_game))
	{
		DrawText("oops", 400, 400, 20, BLACK);
		new_game.active = !new_game.active;
	}

	if(draw_toggle(&toggle_settings))
	{
		//TODO(Fix): Settings
	}

	if(draw_toggle(&toggle_quit))
	{
		CloseWindow();
		exit(0); //TODO(Fix): don't do this, lmao
	}
}