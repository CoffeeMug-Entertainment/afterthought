#include "raylib.h"

#include "stdio.h"

extern Texture2D char_sheet;

static Vector2 pad = (Vector2){10, 40};

void DrawChar(Vector2 sprite_tile, Vector2 world_pos, Color tint)
{
	Rectangle src;
	src.x = sprite_tile.x * 8;
	src.y = sprite_tile.y * 8;
	src.height = 8;
	src.width = 8;

	Rectangle dest;
	dest.x = world_pos.x * 32 + pad.x;
	dest.y = world_pos.y * 32 + pad.y;
	dest.height = 32;
	dest.width = 32;

	DrawTexturePro(char_sheet, src, dest, (Vector2){0, 0}, 0.0f, tint);
}