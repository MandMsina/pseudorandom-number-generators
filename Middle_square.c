#include "Middle_square.h"
void FirstMS(unsigned long int* num, short int* mStart) {
	*num = time(NULL) & m32Mask;
	*mStart = 0;
}
void AlgMS(unsigned long int* num) {
	unsigned long long int square;
	unsigned long long int msm = *num;
	square = (unsigned long long int) (msm)*(msm);
	msm = (square % 1000000000000000) / 100000;
	if ((sizeof(unsigned long int) == 4) || (sizeof(unsigned long long int) == 8)) { *num = msm & m32Mask; }
	else *num = msm;
}
unsigned long int Middle_square(short int* mStart, unsigned long int* num, void* useless) {
	if ((*mStart) || (!*num)) { FirstMS(num, mStart); }
	AlgMS(num);
	return *num;
}