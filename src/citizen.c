#include "citizen.h"
#include "raylib.h"
#include <stdio.h>
#include <string.h>

const char* name_file = "names.txt";
#define NAME_COUNT 4944 //Hardcode for now

const char* default_name = "Stranger";

Citizen citizen_generate()
{
	Citizen new_citizen;
	
	FILE *names_file = fopen(name_file, "r");

	if (names_file == NULL)
	{
		//Failed to open names file, resort to default
		strcpy(new_citizen.name, default_name);
		new_citizen.age = 25;
		return new_citizen;
	}

	unsigned int random_num = GetRandomValue(0, NAME_COUNT);

	char name_str[50];
	unsigned int count = 0;
	while (fgets(name_str, sizeof(name_str), names_file) != NULL) 
	{
		if (count != random_num)
		{
			count += 1;
			continue;
		}
		break;
	}
	fclose(names_file);

	char nullterm = '\0';
	strcat(name_str, &nullterm);

	strcpy(new_citizen.name, name_str);
	new_citizen.age = GetRandomValue(15, 35);
	new_citizen.type = CIT_INACTIVE;

	return new_citizen;
}
