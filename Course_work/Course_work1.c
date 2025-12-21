#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "Functions.h"
#define _CRT_SECURE_NO_DEPRECATE 

int main()
{
	setlocale(LC_CTYPE, "RUS");
	double H, Result_proizvod;
	int v;
	double x, x1;
	double inter1, inter2, step;
	double intmd1, intmd2, TT2;
	double a, b;
	int Retmon;
	char fname[30] = "course_project.txt";
	puts("\t\t _____________________________________________");
	puts("\t\t/                                             \\");
	puts("\t\t|                                             |");
	puts("\t\t|                КАЛЬКУЛЯТОР                  |");
	puts("\t\t|                                             |");
	puts("\t\t|               для функции:                  |");
	puts("\t\t|                                             |");
	puts("\t\t|                                             |");
	puts("\t\t|                                             |");
	puts("\t\t|           /                                 |");
	puts("\t\t|          | 1/arctan(x) , x<-3               |");
	puts("\t\t|          | (cos(x)-sin(x))/x , -3<=x<0      |");
	puts("\t\t|    f(x)=<   5                               |");
	puts("\t\t|          | SUM x^(3*n)/(3*n+2)! , x>=0      |");
	puts("\t\t|          |  n=0                             |");
	puts("\t\t|           \\                                 |");
	puts("\t\t\\_____________________________________________/\n");

	do {
		printf(" _______________________________________________________________________\n/\t\t\tВыберите действие:\t\t\t\t\\\n|\t1-Значение f(x) в точке\t\t\t\t\t\t|\n|\t2-Таблица \
- x -> f(x) на интервале\
\t\t\t\t|\n|\t3-Вычисление определённого интеграла на заданном интервале\t|\n|\t4-Проверка\
 на монотонность на заданном интервале\t\t|\n|\t5-Производная- f'(x) в точке\t\t\t\t\t|\n\\_______________________________________________________________________/\n");
		puts("");
		printf("Действие: ");
		scanf("%d", &v);
		switch (v)
		{
			//ФУНКЦИЯ ДЛЯ ТОЧКИ
		case 1:
			printf("Введите значение x:");
			scanf("%lf", &x);
			double sd = funct(x);
			printf("Результат функции в точке %.3lf равен==%.3lf\n", x, sd);
			append_to_file(fname, x, sd);
			printf("Значение записано в файл %s\n", fname);
			break;


			//ФУНКЦИЯ ДЛЯ ИНТЕРВАЛА
		case 2:
			printf("Введите начало интервала: ");
			scanf("%lf", &inter1);
			printf("Введите конец интервала: ");
			scanf("%lf", &inter2);
			printf("Введите шаг интервала: ");
			scanf("%lf", &step);
			if (inter1 > inter2) {
				printf("Конец интервала меньше начала!\n");
				break;
			}
			printf("|      x       |        f(x)      |\n");
			for (double i = inter1; i <= inter2; i += step) {
				H = funct(i);
				printf("|  %9.3lf   |    %9.3lf     |\n", i, H);
			}
			append_interval_into_file(fname, inter1, inter2, step);
			printf("Интервал добавлен в файл %s\n", fname);
			break;



			//ФУНКЦИЯ ДЛЯ ИНТЕГРАЛА
		case 3:
			printf("Введите начало интервала: ");
			scanf("%lf", &intmd1);
			printf("Введите конец интервала: ");
			scanf("%lf", &intmd2);
			if (intmd1 > intmd2) {
				printf("Конец интервала меньше начала!\n");
				break;
			}

			printf("\t\tМетод средних п-угольников:\n");
			double TT2 = integral(intmd1, intmd2);
			printf("Определённый интеграл на интервале [%.3lf:%.3lf] равен== %lf\n", intmd1, intmd2, TT2);
			break;


			break;
			//Функция для монотонности
		case 4:
			printf("Введите начало интервала: ");
			scanf("%lf", &a);
			printf("Введите конец интервала: ");
			scanf("%lf", &b);
			if (a > b) {
				printf("\nНеправильно введён интервал\n");
				break;
			}
			printf("\n=== ПРОВЕРКА МОНОТОННОСТИ ===\n");
			Retmon = monoton(a, b);
			printf("Результат: ");
			switch (Retmon)
			{
			case CONSTANT:
				printf("ПОСТОЯННА\n");
				break;
			case INCREASING:
				printf("ВОЗРАСТАЕТ\n");
				break;
			case DECREASING:
				printf("УБЫВАЕТ\n");
				break;
			case NOT_DECREASING:
				printf("НЕ УБЫВАЕТ\n");
				break;
			case NOT_INCREASING:
				printf("НЕ ВОЗРАСТАЕТ\n");
				break;
			case NOT_MONOTON:
				printf("НЕМОНОТОННА\n");
				break;
			}
			break;
			//функция для производной
		case 5:
			printf("Введите значение x: ");
			scanf("%lf", &x1);
			Result_proizvod = proizvod(x1);
			printf("Производная в точке %.3lf равна= %.3lf\n", x1, Result_proizvod);
			break;
		default:
			printf("Такой операции с функцией нет\n");
			break;
		}
		char a;
		printf("Продолжить ? (Да - любая клавиша, нет - n)\n");
		getchar();
		if ((a = getchar()) == 'n') break;
	} while (1);
	return 1;
}
