#pragma once
#include "random_generators.h"
#define m15Mask 0x7fff			// ����� ��� ������� 15 �����
#define m16Mask 0xffff			// ����� ��� ������� 16 �����
#define m31Mask 0x7fffffff		// ����� ��� 31 �������� ���
typedef struct ConstMoA{
	short int mother1[10];		//������ ��� ������� 16 �����
	short int mother2[10];		//������ ��� ������� 16 �����
} ConstMoA;
unsigned long int Mother_of_all(short int*, unsigned long int*, void*);
void FirstMoA(short int*, ConstMoA*);
void AlgMoA(unsigned long int*, ConstMoA*);
