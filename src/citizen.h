#ifndef AT_CITIZEN_H
#define AT_CITIZEN_H 1

struct at_citizen_s
{
	char name[255];
	unsigned int age;
};

typedef struct at_citizen_s Citizen;

Citizen citizen_generate();

#endif