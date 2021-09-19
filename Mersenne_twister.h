#pragma once
#include "random_generators.h"
#define MATRIX_A 0x9908b0df   //последняя строка матрицы A
#define s1Mask 0x80000000		//битовая маска старшего бита
#define m31Mask 0x7fffffff		// маска для 31 младшего бит
typedef struct ConstMT {
	unsigned long int xorsh[4];	//массив
	unsigned long int mt[624]; //вектор
	int mti; //инкрементируемый счетчик
} ConstMT;
void FirstMT(short int*, ConstMT*);
void AlgMT(unsigned long int*, ConstMT*);
unsigned long int Mersenne_twister(short int*, unsigned long int*, void*);
