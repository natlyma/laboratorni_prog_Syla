// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// 
//ignor oshibok//
#define _CRT_SECURE_NO_WARNINGS
#define _VCRUNTIME_DISABLED_WARNINGS
//ignor oshibok//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double l_rect(double granica_a, double granica_b, unsigned int intervals);
double r_rect(double granica_a, double granica_b, unsigned int intervals);
double simps(double granica_a, double granica_b, unsigned int intervals);
double trapecia(double granica_a, double granica_b, unsigned int intervals);
double func(double x);

double max_pohibka = 0.00001;

int main()
{
	double granica_a = 1, granica_b = 2; // obmezhennya Syla
	double measurement_error = 0, i1 = 0, i2 = 0;
	int intervals, var, i;
	double integral_sum = 0;

	while (1)
	{
		printf("\n\tThe left boundary a = %.2lf", granica_a);
		printf("\n\tThe right boundary b = %.2lf\n", granica_b);

		//validacia
		do
		{
			printf("\tEnter the number of partition intervals (N>0)\nN=");
			scanf("%u", &intervals);
		} while (intervals <= 0);
		//validacia

		do
		{
			printf("\nChoose the method of calculating:\n");
			printf("\t1. By Left Rectangles:\n");
			printf("\t2. By Right Rectangles:\n");
			printf("\t3. By Trapecia:\n");
			printf("\t4. By Simps:\n");
			scanf("%u", &var);
			if (var != 1 && var != 2 && var != 3 && var != 4)
				printf("\nYou are mistaken\n");
		} while (var != 1 && var != 2 && var != 3 && var != 4);
		system("cls");
		switch (var)
		{
		case 1:
		{
			int Npoh = pohibka(granica_a, granica_b, var);
			double i1 = l_rect(granica_a, granica_b, Npoh);
			integral_sum = l_rect(granica_a, granica_b, intervals);
			printf("\n\n\t*Left Rectangles method*\n");
			printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.6lf \n\tN = %d \n\ti1 = %.6lf \n\tNpoh = %d", granica_a, granica_b, integral_sum, intervals, i1, Npoh);
		}
		break;
		case 2:
		{
			int Npoh = pohibka(granica_a, granica_b, var);
			double i1 = r_rect(granica_a, granica_b, Npoh);
			integral_sum = r_rect(granica_a, granica_b, intervals);
			printf("\n\n\t======*Right Rectangles method*======\n");
			printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.6lf \n\tN = %d \n\ti1 = %.6lf \n\tNpoh = %d", granica_a, granica_b, integral_sum, intervals, i1, Npoh);
		}
		break;
		case 3:
		{
			int Npoh = pohibka(granica_a, granica_b, var);
			double i1 = trapecia(granica_a, granica_b, Npoh);
			integral_sum = trapecia(granica_a, granica_b, intervals);
			printf("\n\n\t======*trapecia method *======\n");
			printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.6lf \n\tN = %d \n\ti1 = %.6lf \n\tNpoh = %d", granica_a, granica_b, integral_sum, intervals, i1, Npoh);
		}
		break;
		case 4:
		{
			int Npoh = pohibka(granica_a, granica_b, var);
			double i1 = simps(granica_a, granica_b, Npoh);
			integral_sum = simps(granica_a, granica_b, intervals);
			printf("\n\n\t======*simps's method *======\n");
			printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.6lf \n\tN = %d \n\ti1 = %.6lf \n\tNpoh = %d", granica_a, granica_b, integral_sum, intervals, i1, Npoh);
		}
		break;
		}
	}
	return 0;
}

double l_rect(double granica_a, double granica_b, unsigned int intervals)
{
	double integral_sum = 0, x = 0, h;
	unsigned int i;
	h = (granica_b - granica_a) / intervals;
	x = granica_a; //x(n=0)
	for (i = 0; i <= (intervals - 1); i++)
	{
		integral_sum += func(x);
		x += h;
	}
	return integral_sum * h;
}
double r_rect(double granica_a, double granica_b, unsigned int intervals)
{
	double integral_sum = 0, x = 0, h;
	unsigned int i;
	h = (granica_b - granica_a) / intervals;
	x = granica_a + h; //x(n=1)
	for (i = 0; i <= intervals; i++)
	{
		integral_sum += func(x);
		x += h;
	}
	return integral_sum * h;
}
double trapecia(double granica_a, double granica_b, unsigned int intervals)
{
	double integral_sum = 0, x = 0, h;
	unsigned int i;
	h = (granica_b - granica_a) / intervals;
	x = granica_a + h; //x(n=1)
	for (i = 0; i <= (intervals - 1); i++)
	{
		integral_sum += (func(x) + func(x + h)) / 2;
		x += h;
	}
	return integral_sum * h;
}
double simps(double granica_a, double granica_b, unsigned int intervals)
{
	double integral_sum = 0, sum1 = 0, sum2 = 0, h = 0;

	h = (granica_b - granica_a) / intervals;

	for (int i = 1; i <= (intervals - 1); i++)
	{
		if (i % 2 != 0)
			sum1 += func(granica_a + h * i);
		else
			sum2 += func(granica_a + h * i);
	}
	return (func(granica_a) + func(granica_b) + 4 * sum1 + 2 * sum2) * h / 3;
}
double func(double x) // îñíîâíà ôóíêö³ÿ   X0
{
	return x/2 * sqrt(pow(x, 2) - 1);// Syla function
}
int pohibka(double granica_a, double granica_b, int var)
{
	switch (var)
	{
	case 1:
	{
		int Npoh = 0, i1, i2;
		do
		{
			Npoh += 2;
			i1 = l_rect(granica_a, granica_b, Npoh);
			i2 = l_rect(granica_a, granica_b, Npoh + 2);
		} while (fabs(i2 - i1) > max_pohibka);
		return Npoh;
	}
	break;
	case 2:
	{
		int Npoh = 0, i1, i2;
		do
		{
			Npoh += 2;
			i1 = r_rect(granica_a, granica_b, Npoh);
			i2 = r_rect(granica_a, granica_b, Npoh + 2);
		} while (fabs(i2 - i1) > max_pohibka);
		return Npoh;
	}
	break;
	case 3:
	{
		int Npoh = 0, i1, i2;
		do
		{
			Npoh += 2;
			i1 = trapecia(granica_a, granica_b, Npoh);
			i2 = trapecia(granica_a, granica_b, Npoh + 2);
		} while (fabs(i2 - i1) > max_pohibka);
		return Npoh;
	}
	break;
	case 4:
	{
		int Npoh = 0, i1, i2;
		do
		{
			Npoh += 2;
			i1 = simps(granica_a, granica_b, Npoh);
			i2 = simps(granica_a, granica_b, Npoh + 2);
		} while (fabs(i2 - i1) > max_pohibka);
		return Npoh;
	}
	break;
	}
}
