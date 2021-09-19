#include "Xorshift.h"
void FirstXor(short int* mStart, ConstXOR* constans) {
	unsigned long int xor = time(NULL);
	unsigned short int sNumber = xor & m16Mask;
	unsigned long int number = xor & m31Mask;
	unsigned long int* p;
	p = constans->xorsh;
	for (int i = 4; i >= 1; i--) {
		number = 30903 * sNumber + (number >> 16);
		*p++ = number & m32Mask;
		sNumber = number & m16Mask;
		*mStart = 0;
	}
}
void AlgXor(unsigned long int* num, ConstXOR* constans) {
	unsigned long int s, t = constans->xorsh[3];
	constans->xorsh[3] = constans->xorsh[2];
	constans->xorsh[2] = constans->xorsh[1];
	constans->xorsh[1] = s = constans->xorsh[0];
	t = t ^ (t << 11);
	t = t ^ (t >> 8);
	constans->xorsh[0] = t ^ s ^ (s >> 19);
	*num = constans->xorsh[0];
}
unsigned long int Xorshift(short int* mStart, unsigned long int* num, void* address) {
	ConstXOR* constans = (ConstXOR*)address;
	if (*mStart) { FirstXor(mStart, constans); }
	AlgXor(num, constans);
	return *num;
}