#ifndef AT_CITIZEN_H
#define AT_CITIZEN_H 1

typedef enum
{
	CIT_INACTIVE,
	CIT_NEET,
	CIT_GATHERER
} citizen_type;

struct at_citizen_s
{
	char name[50];
	unsigned int age;
	citizen_type type;
};

typedef struct at_citizen_s Citizen;

Citizen citizen_generate();

#endif