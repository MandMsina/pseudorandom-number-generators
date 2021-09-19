#include "random_generators.h"
int generate(short int a, unsigned long int numb, unsigned long int* buffer) {
	if ((sizeof(unsigned long int) < 4) || (sizeof(unsigned long long int) < 8)) { printf("Error. Your device don't support this program."); return 1; }
	if (numb < 1) { printf("Error. Invalid quantity of numbers."); return 1; }
	unsigned long int num; //сгенерированное число
	short int mStart = 1; //флаг первого использования алгоритма генерации
	unsigned long int(*algoritm)(short int*, unsigned long int*, void*) = NULL;
	void* constants = NULL;
	if (a == 1) {
		algoritm = LKM;
		ConstLKM cLKM;
		cLKM.m = 16777216;
		cLKM.a = 1140671485;
		cLKM.c = 12820163;
		constants = &cLKM;
	}
	if (a == 2) { 
		algoritm = Mother_of_all;
		ConstMoA cMoA;
		constants = &cMoA;
	}
	if (a == 3) { 
		algoritm = Middle_square;
		constants = NULL;
	}
	if (a == 4) { 
		algoritm = Xorshift; 
		ConstXOR cXOR;
		constants = &cXOR;
	}
	if (a == 5) { 
		algoritm = Mersenne_twister;
		ConstMT cMT;
		constants = &cMT;
	}
	if (algoritm == NULL) { printf("Error. Invalid number of algorithm."); return 1; }
	for (unsigned long int i = 0; i < numb; i++) {
		*(buffer + i) = algoritm(&mStart, &num, constants);
	}
	mStart = 1;
	return 0;
}