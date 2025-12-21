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
	puts("\t\t|                ÊÀËÜÊÓËßÒÎÐ                  |");
	puts("\t\t|                                             |");
	puts("\t\t|               äëÿ ôóíêöèè:                  |");
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
		printf(" _______________________________________________________________________\n/\t\t\tÂûáåðèòå äåéñòâèå:\t\t\t\t\\\n|\t1-Çíà÷åíèå f(x) â òî÷êå\t\t\t\t\t\t|\n|\t2-Òàáëèöà \
- x -> f(x) íà èíòåðâàëå\
\t\t\t\t|\n|\t3-Âû÷èñëåíèå îïðåäåë¸ííîãî èíòåãðàëà íà çàäàííîì èíòåðâàëå\t|\n|\t4-Ïðîâåðêà\
 íà ìîíîòîííîñòü íà çàäàííîì èíòåðâàëå\t\t|\n|\t5-Ïðîèçâîäíàÿ- f'(x) â òî÷êå\t\t\t\t\t|\n\\_______________________________________________________________________/\n");
		puts("");
		printf("Äåéñòâèå: ");
		scanf("%d", &v);
		switch (v)
		{
			//ÔÓÍÊÖÈß ÄËß ÒÎ×ÊÈ
		case 1:
			printf("Ââåäèòå çíà÷åíèå x:");
			scanf("%lf", &x);
			double sd = funct(x);
			printf("Ðåçóëüòàò ôóíêöèè â òî÷êå %.3lf ðàâåí==%.3lf\n", x, sd);
			append_to_file(fname, x, sd);
			printf("Çíà÷åíèå çàïèñàíî â ôàéë %s\n", fname);
			break;


			//ÔÓÍÊÖÈß ÄËß ÈÍÒÅÐÂÀËÀ
		case 2:
			printf("Ââåäèòå íà÷àëî èíòåðâàëà: ");
			scanf("%lf", &inter1);
			printf("Ââåäèòå êîíåö èíòåðâàëà: ");
			scanf("%lf", &inter2);
			printf("Ââåäèòå øàã èíòåðâàëà: ");
			scanf("%lf", &step);
			if (inter1 > inter2) {
				printf("Êîíåö èíòåðâàëà ìåíüøå íà÷àëà!\n");
				break;
			}
			printf("|      x       |        f(x)      |\n");
			for (double i = inter1; i <= inter2; i += step) {
				H = funct(i);
				printf("|  %9.3lf   |    %9.3lf     |\n", i, H);
			}
			append_interval_into_file(fname, inter1, inter2, step);
			printf("Èíòåðâàë äîáàâëåí â ôàéë %s\n", fname);
			break;



			//ÔÓÍÊÖÈß ÄËß ÈÍÒÅÃÐÀËÀ
		case 3:
			printf("Ââåäèòå íà÷àëî èíòåðâàëà: ");
			scanf("%lf", &intmd1);
			printf("Ââåäèòå êîíåö èíòåðâàëà: ");
			scanf("%lf", &intmd2);
			if (intmd1 > intmd2) {
				printf("Êîíåö èíòåðâàëà ìåíüøå íà÷àëà!\n");
				break;
			}

			printf("\t\tÌåòîä ñðåäíèõ ï-óãîëüíèêîâ:\n");
			double TT2 = integral(intmd1, intmd2);
			printf("Îïðåäåë¸ííûé èíòåãðàë íà èíòåðâàëå [%.3lf:%.3lf] ðàâåí== %lf\n", intmd1, intmd2, TT2);
			break;


			break;
			//Ôóíêöèÿ äëÿ ìîíîòîííîñòè
		case 4:
			printf("Ââåäèòå íà÷àëî èíòåðâàëà: ");
			scanf("%lf", &a);
			printf("Ââåäèòå êîíåö èíòåðâàëà: ");
			scanf("%lf", &b);
			if (a > b) {
				printf("\nÍåïðàâèëüíî ââåä¸í èíòåðâàë\n");
				break;
			}
			printf("\n=== ÏÐÎÂÅÐÊÀ ÌÎÍÎÒÎÍÍÎÑÒÈ ===\n");
			Retmon = monoton(a, b);
			printf("Ðåçóëüòàò: ");
			switch (Retmon)
			{
			case CONSTANT:
				printf("ÏÎÑÒÎßÍÍÀ\n");
				break;
			case INCREASING:
				printf("ÂÎÇÐÀÑÒÀÅÒ\n");
				break;
			case DECREASING:
				printf("ÓÁÛÂÀÅÒ\n");
				break;
			case NOT_DECREASING:
				printf("ÍÅ ÓÁÛÂÀÅÒ\n");
				break;
			case NOT_INCREASING:
				printf("ÍÅ ÂÎÇÐÀÑÒÀÅÒ\n");
				break;
			case NOT_MONOTON:
				printf("ÍÅÌÎÍÎÒÎÍÍÀ\n");
				break;
			}
			break;
			//ôóíêöèÿ äëÿ ïðîèçâîäíîé
		case 5:
			printf("Ââåäèòå çíà÷åíèå x: ");
			scanf("%lf", &x1);
			Result_proizvod = proizvod(x1);
			printf("Ïðîèçâîäíàÿ â òî÷êå %.3lf ðàâíà= %.3lf\n", x1, Result_proizvod);
			break;
		default:
			printf("Òàêîé îïåðàöèè ñ ôóíêöèåé íåò\n");
			break;
		}
		char a;
		printf("Ïðîäîëæèòü ? (Äà - ëþáàÿ êëàâèøà, íåò - n)\n");
		getchar();
		if ((a = getchar()) == 'n') break;
	} while (1);
	return 1;
}
