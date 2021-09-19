#include "random_generators.h"
#define NACH 1000				//сгенерируемые числа будут лежать в интервале [1, NACH]

int scan(unsigned long int*); //функция ввода целого числа

int main() {
	setlocale(LC_ALL, "Rus");
	unsigned long int a, numb, c = 1; //переменные для выбора хода выполнения задания
	while (c != 0) {
		a = 1;
		printf("Что вы хотите сделать? \n\t1 - Сгенерировать псевдослучаные числа\n\t2 - Проверить эффективность алгоритмов по времени\n\t0 - Закончить работу\nНомер операции: ");
		if ((scan(&c)) || (c > 2)) { printf("Введен неверный номер операции. Повторите ввод\n"); }
		else {
			if (c == 1) {
				while (a != 0) {
					printf("Каким способом вы хотите получить псевдослучайные числа? \n\t1 - ЛКМ \n\t2 - Mother-of-all \n\t3 - Метод середины квадрата\n\t4 - Xorshift \n\t5 - Вихрь Мерсенна\n\t0 - Выход из меню генерации\nНомер способа: ");
					if ((scan(&a)) || (a == 0) || (a > 5)) { if (a != 0) printf("Введен неверный номер способа. Повторите ввод\n"); }
					else {
						printf("Кол-во чисел, которое вы хотите получить (не более 1000000): ");
						if ((scan(&numb)) || (numb == 0) || (numb > 1000000)) { printf("Введено неверное кол-во. Повторите ввод.\n"); }
						else {
							unsigned long int* buffer = (unsigned long int*) malloc(sizeof(unsigned long int)*numb);
							if (!buffer) { printf("Недостаточно памяти под такое кол-во чисел. Повторите ввод.\n"); }
							else {
								short a1 = (short) a;
								if (generate(a1, numb, buffer)) { return 1; }
								printf("Случайные числа: \n");
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
				printf("Кол-во чисел, с которым будет проведен тест по времени (не более 100000000): ");
				if ((scan(&numb)) || (numb == 0) || (numb > 100000000)) { printf("Введено неверное кол-во. Повторите ввод.\n"); }
				else {
					unsigned long int* buffer = (unsigned long int*) malloc(sizeof(unsigned long int)*numb);
					if (!buffer) { printf("Недостаточно памяти под такое кол-во чисел. Повторите ввод.\n"); }
					else {
						long int start, stop;
						printf("\n");
						for (short int i = 1; i <= 5; i++) {
							start = clock();
							if (generate(i, numb, buffer)) { return 1; }
							stop = clock();
							if (i == 1) { printf("%27s", "ЛКМ: "); }
							if (i == 2) { printf("%27s", "Mother-of-all: "); }
							if (i == 3) { printf("%27s", "Метод середины квадрата: "); }
							if (i == 4) { printf("%27s", "Xorshift: "); }
							if (i == 5) { printf("%27s", "Вихрь Мерсенна: "); }
							printf(" затрачено %.3lf секунд\n", (double)(stop - start) / CLOCKS_PER_SEC);
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
	unsigned long int a; //переменная для ввода
	if (!scanf("%lu", &a)) { while (getchar() != '\n'); return 1; }
	if (getchar() != '\n') { while (getchar() != '\n'); return 1; }
	*A = a;
	return 0;
}
