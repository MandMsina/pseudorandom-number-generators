#pragma once
#include "random_generators.h"
#define MATRIX_A 0x9908b0df   //��������� ������ ������� A
#define s1Mask 0x80000000		//������� ����� �������� ����
#define m31Mask 0x7fffffff		// ����� ��� 31 �������� ���
typedef struct ConstMT {
	unsigned long int xorsh[4];	//������
	unsigned long int mt[624]; //������
	int mti; //���������������� �������
} ConstMT;
void FirstMT(short int*, ConstMT*);
void AlgMT(unsigned long int*, ConstMT*);
unsigned long int Mersenne_twister(short int*, unsigned long int*, void*);
