#include "Mersenne_twister.h"
void FirstMT(short int* mStart, ConstMT* constants) {
	constants->mt[0] = time(NULL);
	for (constants->mti = 1; constants->mti < 624; constants->mti++) {
		constants->mt[constants->mti] = ((unsigned long int)1812433253 * (constants->mt[constants->mti - 1] ^ (constants->mt[constants->mti - 1] >> 30)) + constants->mti);
	} //первая инициализация
	unsigned long int init_key[4] = { 0x123, 0x234, 0x345, 0x456 };
	int key_length = 4;
	int i, j, k;
	i = 1;
	j = 0;
	for (k = 624; k; k--) {
		constants->mt[i] = (constants->mt[i] ^ ((constants->mt[i - 1] ^ (constants->mt[i - 1] >> 30)) * (unsigned long int)1664525)) + init_key[j] + j;
		i++;
		j++;
		if (i >= 624) { constants->mt[0] = constants->mt[623]; i = 1; }
		if (j >= key_length) j = 0;
	}
	for (k = 623; k; k--) {
		constants->mt[i] = (constants->mt[i] ^ ((constants->mt[i - 1] ^ (constants->mt[i - 1] >> 30)) * (unsigned long int)1566083941)) - i;
		i++;
		if (i >= 624) { constants->mt[0] = constants->mt[623]; i = 1; }
	}
	constants->mt[0] = s1Mask;
	*mStart = 0;
}
void AlgMT(unsigned long int* num, ConstMT* constants) {
	static unsigned long int mag01[2] = { 0x0, MATRIX_A };
	if (constants->mti >= 624) {
		int kk;
		for (kk = 0; kk < 227; kk++) {
			*num = (constants->mt[kk] & s1Mask) | (constants->mt[kk + 1] & m31Mask);
			constants->mt[kk] = constants->mt[kk + 397] ^ (*num >> 1) ^ mag01[*num & 0x1];
		}
		*num = (constants->mt[623] & s1Mask) | (constants->mt[0] & m31Mask);
		constants->mt[623] = constants->mt[396] ^ (*num >> 1) ^ mag01[*num & 0x1];

		constants->mti = 0;
	}

	*num = constants->mt[constants->mti++];

	//Закалка
	*num ^= (*num >> 11);
	*num ^= (*num << 7) & 0x9d2c5680;
	*num ^= (*num << 15) & 0xefc60000;
	*num ^= (*num >> 18);
}
unsigned long int Mersenne_twister(short int* mStart, unsigned long int* num, void* address) {
	ConstMT* constants = (ConstMT*) address;
	if (*mStart) { FirstMT(mStart, constants); }
	AlgMT(num, constants);
	return *num;
}