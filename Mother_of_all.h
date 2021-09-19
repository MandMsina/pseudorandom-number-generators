#pragma once
#include "random_generators.h"
#define m15Mask 0x7fff			// маска для младших 15 битов
#define m16Mask 0xffff			// маска для младших 16 битов
#define m31Mask 0x7fffffff		// маска для 31 младшего бит
typedef struct ConstMoA{
	short int mother1[10];		//массив для старших 16 битов
	short int mother2[10];		//массив для младших 16 битов
} ConstMoA;
unsigned long int Mother_of_all(short int*, unsigned long int*, void*);
void FirstMoA(short int*, ConstMoA*);
void AlgMoA(unsigned long int*, ConstMoA*);
