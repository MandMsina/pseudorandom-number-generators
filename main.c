#include "random_generators.h"
#define NACH 1000				//������������� ����� ����� ������ � ��������� [1, NACH]

int scan(unsigned long int*); //������� ����� ������ �����

int main() {
	setlocale(LC_ALL, "Rus");
	unsigned long int a, numb, c = 1; //���������� ��� ������ ���� ���������� �������
	while (c != 0) {
		a = 1;
		printf("��� �� ������ �������? \n\t1 - ������������� �������������� �����\n\t2 - ��������� ������������� ���������� �� �������\n\t0 - ��������� ������\n����� ��������: ");
		if ((scan(&c)) || (c > 2)) { printf("������ �������� ����� ��������. ��������� ����\n"); }
		else {
			if (c == 1) {
				while (a != 0) {
					printf("����� �������� �� ������ �������� ��������������� �����? \n\t1 - ��� \n\t2 - Mother-of-all \n\t3 - ����� �������� ��������\n\t4 - Xorshift \n\t5 - ����� ��������\n\t0 - ����� �� ���� ���������\n����� �������: ");
					if ((scan(&a)) || (a == 0) || (a > 5)) { if (a != 0) printf("������ �������� ����� �������. ��������� ����\n"); }
					else {
						printf("���-�� �����, ������� �� ������ �������� (�� ����� 1000000): ");
						if ((scan(&numb)) || (numb == 0) || (numb > 1000000)) { printf("������� �������� ���-��. ��������� ����.\n"); }
						else {
							unsigned long int* buffer = (unsigned long int*) malloc(sizeof(unsigned long int)*numb);
							if (!buffer) { printf("������������ ������ ��� ����� ���-�� �����. ��������� ����.\n"); }
							else {
								short a1 = (short) a;
								if (generate(a1, numb, buffer)) { return 1; }
								printf("��������� �����: \n");
								for (unsigned long int i = 0; i < numb; i++) {
									printf("%lu\t", buffer[i]%NACH+1);
								}
								printf("\n");
								free(buffer);
							}
						}
					}
				}
			}
			if (c == 2) {
				printf("���-�� �����, � ������� ����� �������� ���� �� ������� (�� ����� 100000000): ");
				if ((scan(&numb)) || (numb == 0) || (numb > 100000000)) { printf("������� �������� ���-��. ��������� ����.\n"); }
				else {
					unsigned long int* buffer = (unsigned long int*) malloc(sizeof(unsigned long int)*numb);
					if (!buffer) { printf("������������ ������ ��� ����� ���-�� �����. ��������� ����.\n"); }
					else {
						long int start, stop;
						printf("\n");
						for (short int i = 1; i <= 5; i++) {
							start = clock();
							if (generate(i, numb, buffer)) { return 1; }
							stop = clock();
							if (i == 1) { printf("%27s", "���: "); }
							if (i == 2) { printf("%27s", "Mother-of-all: "); }
							if (i == 3) { printf("%27s", "����� �������� ��������: "); }
							if (i == 4) { printf("%27s", "Xorshift: "); }
							if (i == 5) { printf("%27s", "����� ��������: "); }
							printf(" ��������� %.3lf ������\n", (double)(stop - start) / CLOCKS_PER_SEC);
						}
						free(buffer);
						printf("\n");
					}
				}
			}
		}
	}
	return 0;
}


int scan(unsigned long int*A) {
	unsigned long int a; //���������� ��� �����
	if (!scanf("%lu", &a)) { while (getchar() != '\n'); return 1; }
	if (getchar() != '\n') { while (getchar() != '\n'); return 1; }
	*A = a;
	return 0;
}
