#include "citizen.h"
#include "fix_string.h"
#include "raylib.h"
#include <stdio.h>

const char* name_file = "./assets/names.txt";
#define BUF_SIZE 1 << 16
char buffer[BUF_SIZE];
fix_string list_as_string;
fix_string *names_list;
static unsigned int names_count = 0;

void load_names_list()
{
	FILE *names_file = fopen(name_file, "r");
	unsigned int items = fread(buffer, sizeof(buffer[0]), BUF_SIZE, names_file);
	fclose(names_file);
	list_as_string = cstring_to_fix_string(buffer);

	names_list = fix_string_split_by_char(&list_as_string, '\n', &names_count);

	printf("Loaded %i names\n", names_count);
}

const char* default_name = "Stranger";

Citizen citizen_generate()
{
	if(names_count == 0) load_names_list();
	Citizen new_citizen;
	
	if (names_count == 0)
	{
		//Failed to open names file, resort to default
		new_citizen.name = cstring_to_fix_string(default_name);
		new_citizen.age = 25;
		return new_citizen;
	}

	unsigned int random_num = GetRandomValue(0, names_count - 1);

	new_citizen.name = names_list[random_num];
	new_citizen.age = GetRandomValue(15, 35);
	new_citizen.type = CIT_INACTIVE;

	return new_citizen;
	
}
