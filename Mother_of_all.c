#include "Mother_of_all.h"
void AlgMoA(unsigned long int* result, ConstMoA* constans) {
	unsigned long int number1, number2;
	memmove(constans->mother1 + 2, constans->mother1 + 1, 8 * sizeof(short));
	memmove(constans->mother2 + 2, constans->mother2 + 1, 8 * sizeof(short));
	number1 = constans->mother1[0];
	number2 = constans->mother2[0];
	number1 += 1941 * constans->mother1[2] + 1860 * constans->mother1[3] + 1812 * constans->mother1[4] + 1776 * constans->mother1[5] + 1492 * constans->mother1[6] + 1215 * constans->mother1[7] + 1066 * constans->mother1[8] + 12013 * constans->mother1[9];
	number2 += 1111 * constans->mother2[2] + 2222 * constans->mother2[3] + 3333 * constans->mother2[4] + 4444 * constans->mother2[5] + 5555 * constans->mother2[6] + 6666 * constans->mother2[7] + 7777 * constans->mother2[8] + 9272 * constans->mother2[9];
	constans->mother1[0] = number1 / 65536;
	constans->mother2[0] = number2 / 65536;
	constans->mother1[1] = m16Mask & number1;
	constans->mother2[1] = m16Mask & number2;
	*result = (((long)constans->mother1[1]) << 16) + (long)constans->mother2[1];
}
void FirstMoA(short int* mStart, ConstMoA* constans) {
	short int n, *p;
	unsigned long int number;
	unsigned long int seed;
	unsigned short int sNumber;
	seed = time(NULL);
	sNumber = seed & m16Mask;
	number = seed & m31Mask;
	p = constans->mother1;
	for (n = 18; n >= 1; n--) {
		number = 30903 * sNumber + (number >> 16);
		*p++ = sNumber = number & m16Mask;
		if (n == 10) {
			p = constans->mother2;
		}
	}
	constans->mother1[0] &= m15Mask;
	constans->mother2[0] &= m15Mask;
	*mStart = 0;
}
unsigned long int Mother_of_all(short int* mStart, unsigned long int* result, void* address) {
	ConstMoA* constans = (ConstMoA*)address;
	if (*mStart) { FirstMoA(mStart, constans); }
	AlgMoA(result, constans);
	return *result;
}