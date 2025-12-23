#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

#include "Functions.h"
#define ACCURACY_for_Integral 400
#define ACCURACY_for_Monoton 100

double funct(double x)
{
	double result = 0.0;
	double fact[] = {
		2.0,//2!
		120.0,//5!
		40320.0,//8!
		39916800.0,//11!
		87178291200.0,//14!
		355687428096000.0//17!
	};

	if (x < -3.0) result = 1.0 / atan(x);
	if (-3.0 <= x && x < 0.0) {
		if (fabs(x) < 1e-5) result = -(-1 + pow(x, 2)) / 2.0;
		else result = (cos(x) - sin(x)) / x;
	}
	else for (int n = 0; n <= 5; n++)
		{
			result += pow(x, 3 * n) / fact[n];
		}

	

	return result;
}

int table_for_interval(double inter1, double inter2, double step) {
	if (step <= 0) return 0;
	printf("\nТаблица:\n");
	printf("+-----------+-----------+\n");
	printf("|    x      |   f(x)    |\n");
	printf("+-----------+-----------+\n");

	for (double x = inter1; x <= inter2; x += step) {
		printf("| %9.3lf | %9.3lf |\n", x, funct(x));
	}

	printf("+-----------+-----------+\n");
	return 1;
}
//Вычисление определенного интергала===========================================
double integral(double a, double b)
{
	//метод средних п-угольникво
	double AA;
	double h2 = (b - a) / ACCURACY_for_Integral;
	double sum4 = 0.0;

	for (int i = 0; i < ACCURACY_for_Integral; i++) {
		double z2 = a + (i + 0.5) * h2;
		sum4 += funct(z2);

	}

	AA = sum4 * h2;
	return AA;

}
//Определение монотонности на интервале================================================
MONOTONTYPE monoton(double a, double b)
{
	double st = (b - a) / (ACCURACY_for_Monoton - 1);
	int incr = 1;
	int decr = 1;
	int constant = 1;
	double Nach = funct(a);

	for (int i = 1; i < ACCURACY_for_Monoton; i++) {
		double B = a + i * st;
		double Konec = funct(B);

		if (Konec < Nach) incr = 0;
		if (Konec > Nach) decr = 0;
		if (fabs(Konec - Nach) > 1e-10) constant = 0;

		Nach = Konec;
	}

	if (constant) return CONSTANT;
	else if (incr && !decr) return INCREASING;
	else if (decr && !incr) return DECREASING;
	else return NOT_MONOTON;
}
//Вычисление производной в точке======================================================================

double proizvod(double x) {
	double h = 1e-5;
	if (fabs(x + 3.0) < 0.1 || fabs(x) < 0.1) h = 1e-7;
	double Pr_res = (funct(x + h) - funct(x - h)) / (2 * h);
	return Pr_res;
}
//Запись в файл значения функции в точке
int append_to_file(char* fname, double s) {
	FILE* out;
	if ((out = fopen(fname, "at")) == NULL) {
		return 0;
	}

	fprintf(out, "Результат функции в точке %.3lf равен==%.3lf\n", s, funct(s));
	fclose(out);
	return 1;
}
//Запись в файл значений функции на интервале
int append_interval_into_file(char* fname, double a, double b, double st) {
	FILE* out;
	if ((out = fopen(fname, "at")) == NULL) {
		return 0;
	}
	fprintf(out, "\n=== ТАБЛИЦА ЗНАЧЕНИЙ ФУНКЦИИ ===\n");
	fprintf(out, "Интервал: [%.3lf, %.3lf], шаг: %.3lf\n", a, b, st);
	fprintf(out, "+-----------+-------------+\n");
	fprintf(out, "|     x     |    f(x)     |\n");
	fprintf(out, "+-----------+-------------+\n");

	// Записываем значения
	for (double i = a; i <= b; i += st) {
		double value = funct(i);
		fprintf(out, "| %9.3lf | %11.3lf |\n", i, value);
	}

	fprintf(out, "+-----------+-------------+\n\n");
	fclose(out);
	return 1;
}

