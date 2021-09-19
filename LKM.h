#pragma once
#include "random_generators.h"
typedef struct ConstLKM {
	int m;
	int a;
	int c;
} ConstLKM;
unsigned long int LKM(short int*, unsigned long int*, void*);
void FirstLKM(unsigned long int*, short int*);
void AlgLKM(unsigned long int*, ConstLKM*);

