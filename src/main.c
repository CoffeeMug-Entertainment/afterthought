#include "raylib.h"
#include <stdio.h> 


int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	InitWindow(1024, 576, "Afterthought");
	SetTargetFPS(60);

	while (!WindowShouldClose()) 
	{
		BeginDrawing();
		{
			ClearBackground(RAYWHITE);
			DrawText("Hello, World!", GetScreenWidth() / 2 - (3 * 20), GetScreenHeight() / 2, 20, LIGHTGRAY);
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}