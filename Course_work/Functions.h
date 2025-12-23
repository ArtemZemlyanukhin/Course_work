#pragma once
#ifndef ARRAYS_H
#define ARRAYS_H
typedef enum {
	CONSTANT,
	INCREASING,
	DECREASING,
	NOT_DECREASING,
	NOT_INCREASING,
	NOT_MONOTON
}MONOTONTYPE;
/**
 * Перечисление для классификации монотонности функции.
 *
 * Константы:
 *   CONSTANT- Функция постоянна на интервале
 *   INCREASING - Функция строго возрастает на интервале
 *   DECREASING - Функция строго убывает на интервале
 *   NOT_DECREASING - Функция не убывает на интервале(возрастает или постоянна)
 *	 NOT_INCREASING - Функция не возрастает на интервале(убывает или постоянна)
 *	 NOT_MONOTON - Функция немонотонна на интервале(имеет точки экстремума)
 */
double funct(double x);
/**
  * Вычисление значения функции в точке
  * @param x-значение аргумента
  * @return значение функции в точке x
  */
int table_for_interval(double inter1, double inter2, double step);
/**
  * Вывод на экран таблицы значений функции
  * @param inter1-начало интервала
  * @param inter2-конец интервала
  * @param step-шаг интервала
  * @return 1 при успешном выводе таблицы, 0 при ошибке ввода шага интервала
  */
double integral(double a, double b);
/**
  * Вычисление определённого интеграла методом средних прямоугольников
  * @param a-нижний предел интегрирования
  * @param b-верхний предел интегрирования
  * @return значение определённого интеграла на интервале
  */
MONOTONTYPE monoton(double a, double b);
/**
  * Определение типа монотонности функции на интервале
  * @param a-начало интервала
  * @param b-конец интервала
  * @return константа типа MONOTONTYPE
  */
double proizvod(double x);
/**
  * Вычисление производной в точке
  * @param x-точка, в которой вычисляется производная
  * @return значение производной в точке x
  */
int append_to_file(char* fname, double s);
/**
  * Запись результата вычисления функции в точке в файл
  * @param fname-имя файла
  * @param s-значение аргумента x
  * @return 1 при успехе, 0 при ошибке
  */
int append_interval_into_file(char* fname, double a, double b, double st);
/**
  * Запись таблицы значений функции на интервале в файл
  * @param fname-имя файла
  * @param a-начало интервала
  * @param b-конец интервала
  * @param st-шаг табулирования
  * @return 1 при успехе, 0 при ошибке
  */
#endif
