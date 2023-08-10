#include "ui.h"
#include "raygui.h"

bool draw_toggle(Toggle* toggle)
{
	return GuiToggle(toggle->rect, toggle->text, toggle->active);
}

bool draw_window(Window* win)
{
	return GuiWindowBox(win->rect, win->title);
}
