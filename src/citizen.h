#ifndef AT_CITIZEN_H
#define AT_CITIZEN_H 1

#include "fix_string.h"

typedef enum
{
	CIT_INACTIVE,
	CIT_NEET,
	CIT_GATHERER
} citizen_type;

struct at_citizen_s
{
	fix_string name;
	unsigned int age;
	citizen_type type;
};

typedef struct at_citizen_s Citizen;

Citizen citizen_generate();

#endif