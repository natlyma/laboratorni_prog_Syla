// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //
// LABKU ROBILI: SYZKO, SYLA, FOLVARKOVA //

//ignor oshibok//
#define _CRT_SECURE_NO_WARNINGS
#define _VCRUNTIME_DISABLED_WARNINGS
//ignor oshibok//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int main()
{
	double F, x1, x2, delta;
	uint32_t var, N;

	printf("Variant vedennya 1 or 2? : "); // vibor metoda
	scanf("%u", &var);

	//validacia//
	while (var != 1 && var != 2)
	{
		printf("ERROR! Reenter ihfo\n\r");
		printf("Variant vedennya 1 or 2? : ");
		scanf("%u", &var);
	}
	//validacia//

	switch (var)
	{
	case 1:// metod 1
	{
		//vvod dannih//
		printf("\n\rx1 = ");
		scanf("%lf", &x1);
		printf("\n\rx2 = ");
		scanf("%lf", &x2);
		printf("\n\r(N>0) N = ");
		scanf("%u", &N);
		//vvod dannih//

		//validacia//
		while (N < 1)
		{
			printf("ERROR! Vvedit N > 0 \n\r");
			printf("N=");
			scanf("%u", &N);
		}
		//validacia//

		delta = (x2 - x1) / (N - 1);
		system("cls");
		printf("\n\r----------------------------------");
		printf("\n\r|   N   |     X     |      F(X)     |");
		printf("\n\r----------------------------------\n\r");
		for (int32_t i = 1; i <= N; i++)
		{
			printf("|%4d   |%10.2f  |%12.2f |", i, x1, F);
			printf("\n\r----------------------------------\n\r");
			x1 += delta;
			F = (pow(x1 - 200, 5) - pow(x1 - 100, 3) - 50 * x1 - 25);

			////////////////////////////zakonchilos` mesto////////////////////////////////
			if (i % 12 == 0)
			{
				printf("Press any key\n\r");
				getch();
			}
			////////////////////////////zakonchilos` mesto////////////////////////////////

		}
	}
	break;
	case 2:// metod 2
	{

		printf("\nx1 = ");
		scanf("%lf", &x1);
		printf("\nx2 = ");
		scanf("%lf", &x2);
		printf("\ndelta = ");
		scanf("%lf", &delta);

		//validacia//
		while (delta < 1.0)
		{
			printf("ERROR! Vvedit delta > 0 \n");
			printf("delta=");
			scanf("%lf", &delta);
		}
		//validacia//
		system("cls");
		printf("\n\r----------------------------------");
		printf("\n\r|   N   |     X     |      F(X)     |");
		printf("\n\r----------------------------------\n\r");
		for (int i = 1;x1 <= x2;i++)
		{
			printf("|%4d   |%10.2f  |%12.2f |", i, x1, F);
			printf("\n\r----------------------------------\n\r");
			x1 += delta;
			F = (pow(x1 - 200, 5) - pow(x1 - 100,3) - 50 * x1 - 25 );
			////////////////////////////ZAKONCHILOS` MESTO////////////////////////////////
			if (i % 12 == 0)
			{
				printf("Press any key\n\r");
				getch();
			}
			////////////////////////////ZAKONCHILOS` MESTO////////////////////////////////
		}
	}
	break;
	}
	return 0;
}
