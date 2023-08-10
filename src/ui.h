#ifndef AT_UI_H
#define AT_UI_H

#include "raylib.h"

struct at_toggle_s
{
	Rectangle rect;
	const char* text;
	bool active;
};

typedef struct at_toggle_s Toggle;

struct at_window_s
{
	Rectangle rect;
	const char* title;
	bool active;
};

typedef struct at_window_s Window;

bool draw_toggle(Toggle* toggle);
bool draw_window(Window* win);

#endif