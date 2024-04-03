#include "world.h"
#include "citizen.h"
#include "settlement.h"
#include "entity.h"

#include "ui.h"
#include "drawing.h"

#include "raygui.h"
#include "raylib.h"
#include "raymath.h"

#include <stdio.h>
#include <string.h>

#include "pathfinding.h"

enum GAME_TABS
{
	TAB_MAP,
	TAB_SETTLEMENT,
	TAB_CITIZENS
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

World game_world;
unsigned int entity_count = 0;
Entity entities[256];
Settlement settlements[3];
Settlement *player_settlement;
char map_str[WORLD_WIDTH * WORLD_HEIGHT + WORLD_HEIGHT];

typedef void (*init_fpt)(struct entity_s*);

Entity *create_entity(init_fpt init_func, Vector2 pos)
{
	//TODO BOunds check
	Entity *entity = &entities[entity_count++];
	entity->flags = EF_ACTIVE;
	entity->pos = pos;
	init_func(entity);
	return entity;
}


//Settlement Screen;
Window production_window;
Window storage_window;


const char* text[] =
{
		"Map",
		"Settlement",
		"Citizens",
		"Fourth"
};


#include "entities/george.h"
#include "entities/gatherer.h"
void ingame_init()
{
	tab_game.rect = (Rectangle){10, 10, GetScreenWidth() - 10, 30};
	tab_game.text = text;
	tab_game.count = 4;
	tab_game.active = 0;

	settlements[0] = settlement_generate();

	player_settlement = &settlements[0];
	player_settlement->alignment = SET_PLAYER;
	strcpy(player_settlement->name, "Your Settlement");

	for (int i = 1; i < 3; ++i)
	{
		settlements[i] = settlement_generate();
	}


	generate_map(&game_world);

	for (int i = 0; i < 256; ++i)
	{
		entities[0].flags = EF_NONE;
	}

	//create_entity(george_init, (Vector2){0, 0});
	create_entity(gatherer_init, player_settlement->location);

	//Settlement Screen
	production_window.title = "Production";
	production_window.rect = (Rectangle){10, 60, 200, 200};
	production_window.active = true;

	storage_window.title = "Storage";
	storage_window.rect = (Rectangle){220, 60, 200, 200};
	storage_window.active = true;
}

void ingame_tick(void)
{
	entities[0].tick(&entities[0]);

	for (int i = 0; i < 256; ++i)
	{
		Entity *en = &entities[i];
		if (!(en->flags & EF_ACTIVE)) continue;

		if (en->flags & EF_MOVABLE)
		{
			en->move_dir = path_move_dir(en->pos, en->target_pos);
			en->pos = Vector2Add(en->pos, en->move_dir);
			en->move_dir = Vector2Zero();
		}

		if(en->tick)en->tick(en);
	}

	for (int i = 0; i < 3; ++i)
	{
		settlement_tick(&settlements[i]);
	}
}


void map_draw()
{
	for(int y = 0; y < WORLD_HEIGHT; ++y)
	{
		for(int x = 0; x < WORLD_WIDTH; ++x)
		{
			Vector2 sheet_tile = get_tile(&game_world, x, y)->spritesheet_pos;
			DrawChar(sheet_tile, (Vector2){x, y}, RAYWHITE);
		}
	}

	DrawChar((Vector2){0, 1}, player_settlement->location, YELLOW);
	for (int i = 1; i < 3; ++i)
	{
		Color set_col = RAYWHITE;
		if (settlements[i].alignment == SET_ALLY)
		{
			set_col = GREEN;
		}
		else if (settlements[i].alignment == SET_ENEMY)
		{
			set_col = RED;
		}
		DrawChar((Vector2){0, 1}, settlements[i].location, set_col);
	}

	for (int i = 0; i < entity_count; ++i)
	{
		DrawChar(entities[i].spritesheet_pos, entities[i].pos, GREEN);
	}
}

#define SUBWIND_CHAR_SIZE 10
#define SUBWIND_TAB_PAD 25
#define SUBWIND_CHAR_MARGIN 4

void settlement_draw()
{
	DrawText(player_settlement->name, 10, 42, 18, RAYWHITE);
	//Production
	draw_window(&production_window);
	DrawText("Wood: ", production_window.rect.x + SUBWIND_CHAR_MARGIN, production_window.rect.y + SUBWIND_TAB_PAD + SUBWIND_CHAR_MARGIN, SUBWIND_CHAR_SIZE, BLACK);
	char wood_amt[10];
	snprintf(wood_amt, 10,"%d", player_settlement->prod_wood);
	DrawText(wood_amt, production_window.rect.x + 6 * SUBWIND_CHAR_SIZE + SUBWIND_CHAR_MARGIN, production_window.rect.y + SUBWIND_TAB_PAD + SUBWIND_CHAR_MARGIN, SUBWIND_CHAR_SIZE, BLACK);

	DrawText("Food: ", production_window.rect.x + SUBWIND_CHAR_MARGIN, production_window.rect.y + SUBWIND_TAB_PAD + SUBWIND_CHAR_SIZE + SUBWIND_CHAR_MARGIN, SUBWIND_CHAR_SIZE, BLACK);
	snprintf(wood_amt, 10, "%d", player_settlement->prod_food);
	DrawText(wood_amt, production_window.rect.x + 6 * SUBWIND_CHAR_SIZE + SUBWIND_CHAR_MARGIN, production_window.rect.y + SUBWIND_TAB_PAD + SUBWIND_CHAR_SIZE + SUBWIND_CHAR_MARGIN, SUBWIND_CHAR_SIZE, BLACK);

	//Storage
	draw_window(&storage_window);
	DrawText("Wood: ", storage_window.rect.x + SUBWIND_CHAR_MARGIN, storage_window.rect.y + SUBWIND_TAB_PAD + SUBWIND_CHAR_MARGIN, SUBWIND_CHAR_SIZE, BLACK);
	snprintf(wood_amt, 10, "%d", player_settlement->wood);
	DrawText(wood_amt, storage_window.rect.x + 6 * SUBWIND_CHAR_SIZE + SUBWIND_CHAR_MARGIN, storage_window.rect.y + SUBWIND_TAB_PAD + SUBWIND_CHAR_MARGIN, SUBWIND_CHAR_SIZE, BLACK);

	DrawText("Food: ", storage_window.rect.x + SUBWIND_CHAR_MARGIN, storage_window.rect.y + SUBWIND_TAB_PAD + SUBWIND_CHAR_SIZE + SUBWIND_CHAR_MARGIN, SUBWIND_CHAR_SIZE, BLACK);
	snprintf(wood_amt, 10, "%d", player_settlement->food);
	DrawText(wood_amt, storage_window.rect.x + 6 * SUBWIND_CHAR_SIZE + SUBWIND_CHAR_MARGIN, storage_window.rect.y + SUBWIND_TAB_PAD + SUBWIND_CHAR_SIZE + SUBWIND_CHAR_MARGIN, SUBWIND_CHAR_SIZE, BLACK);

}

#include <stdlib.h>

void citizens_draw()
{
	static bool loaded_names = false;

	static const char *list_items[SET_MAX_CITIZENS];
	static int scrollindex;
	static int active_element = 0;
	static int active_count = 0;

	if (!loaded_names)
	{
		for (int i = 0; i < SET_MAX_CITIZENS; ++i)
		{
			Citizen *current_citizen = &player_settlement->citizens[i];
			if (current_citizen->type == CIT_INACTIVE) continue;

			const char *temp = fix_string_to_cstring(&current_citizen->name);
			//strcpy(list_items[active_count], temp);
			list_items[active_count] = temp;
			//free(temp);

			fix_string_print("Added Name: %z\n", current_citizen->name);
			active_count += 1;

			fix_string_print("loaded_names: %i\n", loaded_names);
			loaded_names = true;
		}
	}

	//active_element = GuiListView((Rectangle){10, 50, 200, 600}, list_items, &scrollindex, active_element); //unused because semicolons
	active_element = GuiListViewEx((Rectangle){10, 50, 200, 600}, list_items, active_count, NULL, &scrollindex, active_element);
}

void ingame_draw()
{
	ClearBackground(DARKGRAY);
	GuiTabBar(tab_game.rect, tab_game.text, tab_game.count, &tab_game.active);

	switch(tab_game.active)
	{
		case TAB_MAP:
			map_draw();
			break;
		case TAB_SETTLEMENT:
			settlement_draw();
			break;
		case TAB_CITIZENS:
			citizens_draw();
		default:
			break;
	}
}
