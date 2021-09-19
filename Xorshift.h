#pragma once
#include "random_generators.h"
typedef struct ConstXOR {
	unsigned long int xorsh[4];
} ConstXOR;
void FirstXor(short int* , ConstXOR*);
void AlgXor(unsigned long int* , ConstXOR*);
unsigned long int Xorshift(short int* , unsigned long int* , void*);
