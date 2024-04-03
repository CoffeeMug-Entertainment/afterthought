#ifndef FIX_STRING_RAYLIB_H
#define FIX_STRING_RAYLIB_H

#include "fix_string.h"
#include "raylib.h"

void fix_string_DrawText(fix_string text, int posX, int posY, int fontSize, Color color);
void fix_string_DrawTextEx(Font font, fix_string text, Vector2 position, float fontSize, float spacing, Color tint);

#endif


