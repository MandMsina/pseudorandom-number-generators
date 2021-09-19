#include "LKM.h"
void AlgLKM(unsigned long int* exresult, ConstLKM* constans) {
	unsigned long int result = (constans->a*(*exresult) + constans->c) % constans->m;
	*exresult = result;
}
void FirstLKM (unsigned long int* seed, short int* mStart) {
	*seed = time(NULL);
	*mStart = 0;
}
unsigned long int LKM(short int* mStart, unsigned long int* result, void* address) {
	ConstLKM* constans = (ConstLKM*) address;
	if (*mStart) { FirstLKM(result, mStart); }
	AlgLKM(result, constans);
	return *result;
}