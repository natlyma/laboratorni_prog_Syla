#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define N 30


int main()
{   // ×àñòèíà êîäó ç ËÐ1
    int width = 55;
	int nColWidth = 5;
    int xColWidth = 21;
    int fColWidth = 25;

    // Çì³íí³ ËÐ5
    char group_name [N];
    char student_name [N];
    unsigned int j,i, num_points;
    double x1, x2, delta, F;
    double * C;

    FILE * fp_input, * output, * outbin;

    fp_input = fopen ("LR5.txt", "r");
    if (fp_input == NULL){
        printf ("Cannot open file!!!\n");
        printf ("Press any key to exit...");
        getch();
        exit(1);
    }

    fgets (group_name, N, fp_input);
    fgets (student_name, N, fp_input);
    fscanf (fp_input, "%lf", &x1);
    fscanf (fp_input, "%lf", &x2);
    fscanf (fp_input, "%u", &num_points);
    fscanf (fp_input, "%lf", &delta);


    printf ("%s", group_name);
    printf ("%s", student_name);
    printf ("\n%.0lf", x1);
    printf ("\n%.0lf", x2);
    printf ("\n%u", num_points);
    printf ("\n%.0lf", delta);


    output = fopen ("out.txt", "w");
    if (output == NULL){
        printf ("Cannot open file!!!\n");
        printf ("Press any key to exit...");
        getch();
        exit(1);
    }
    outbin = fopen ("out_bin.bin", "wb");
    if (outbin == NULL){
        printf ("Cannot open file!!!\n");
        printf ("Press any key to exit...");
        getch();
        exit(1);
    }

   // îáðàõóíîê ïåðøîãî çíà÷åííÿ ôóíêö³¿
   F = ((x + 100) * sin(x / 5) - 5 * (x - 10) - 2100);
   // çàïèñ çíà÷åíü ó ôàéë bin
   fwrite (&num_points, sizeof(unsigned int), 1, outbin);
//---------------------------------------------
// Çàïèñ çíà÷åíü ó ôàéëè txt òà bin
	// Ââåðõ òàáëèö³
	fprintf(output, "X1 =  %4.2lf, X2 = %4.2lf, delta = %4.2lf\n", x1, x2, delta);
    // Õåäåð òàáëèö³
	for (int i = 1; i <= width; i++)
		fprintf(output, "*");
	fprintf(output,"\n");
	fprintf(output, "*  N  *          X          *          F(X)           *\n");
	for (int i = 1; i <= width; i++)
		fprintf(output, "*");
	fprintf(output,"\n");

    // Îñíîâà òàáëèö³ (íîìåð òî÷êè, çíà÷åííÿ àðãóìåíòó òà ôóíêö³¿)
    for (j = 0; j < num_points; j++)
	{
		// draw plus-minus line
		for (int i = 1; i <= width; i++)
        {
		if (i == 1 || i == (nColWidth + 2) || i == (xColWidth + nColWidth + 3) || i == (xColWidth + nColWidth + fColWidth + 4))
			fprintf(output, "+");
		else
			fprintf(output, "-");
        }
            fprintf(output, "\n");
		// end of the plus-minus line

		F = ((x + 100) * sin(x / 5) - 5 * (x - 10) - 2100);

		fprintf(output, "|%5u|           %10.2lf|               %10.2lf|\n", j, x1, F);


		// çàïèñ çíà÷åíü ó ôàéë outbin
		fwrite (&x1, sizeof(double), 1, outbin);
	    fwrite (&F, sizeof(double), 1, outbin);
	    //

		// increment
		x1 += delta;
	}
	// draw plus-minus line
		for (int i = 1; i <= width; i++)
        {
		if (i == 1 || i == (nColWidth + 2) || i == (xColWidth + nColWidth + 3) || i == (xColWidth + nColWidth + fColWidth + 4))
			fprintf(output, "+");
		else
			fprintf(output, "-");
        }
            fprintf(output, "\n");
    // end of the plus-minus line

    fprintf (output,"\n%s", group_name);
    fprintf (output,"%s", student_name);


    if ((fclose(fp_input) != 0) || (fclose(output) != 0) || (fclose(outbin)) != 0)
        printf ("\nError");

    outbin = fopen ("out_bin.bin", "rb");
    if (outbin == NULL){
        printf ("Cannot open file!!!\n");
        printf ("Press any key to exit...");
        getch();
        exit(1);
    }

    num_points = 0;
    x1 = 0;
    F = 0;
    fread(&num_points, sizeof(unsigned int), 1, outbin);
    printf("\n\nnumber of points = %u\n\n", num_points);

    C = (double *) malloc (2 * num_points * sizeof(double));
    if ( C == NULL){
        printf ("\nError\n");
        printf ("Press any key to exit...");
        getch();
        exit (1);
    }
    fread (C, sizeof(double), 2 * num_points, outbin); // çàïèñ ïàð àðãóìåíò - çíà÷åííÿ ³ç á³í ôàéëó â ìàñèâ

      // Õåäåð òàáëèö³
	for (int i = 1; i <= width; i++)
		printf("*");
	printf("\n");
	printf("*  N  *          X          *          F(X)           *\n");
	for (int i = 1; i <= width; i++)
		printf("*");
	printf("\n");

    //
     // Òàáëèöÿ ³ç çíà÷åííÿìè îòðèìàíèìè ³ç á³íàðíîãî ôàéëó
     for (j = 0; j < (num_points); j++)
        {
    // Ãðàô³êà ç ËÐ1
        for (int i = 1; i <= width; i++)
        {
		if (i == 1 || i == (nColWidth + 2) || i == (xColWidth + nColWidth + 3) || i == (xColWidth + nColWidth + fColWidth + 4))
			printf("+");
		else
			printf("-");
        }
        printf("\n");
    // Ê³íåöü ãðàô³êè
           x1 = C [j + j];
           F = C [j + j + 1];
           printf("|%5u|           %10.2lf|               %10.2lf|\n", j, x1, F);
        }
    // Ãðàô³êà
     for (int i = 1; i <= width; i++)
        {
		if (i == 1 || i == (nColWidth + 2) || i == (xColWidth + nColWidth + 3) || i == (xColWidth + nColWidth + fColWidth + 4))
			printf("+");
		else
			printf("-");
        }
    // Ê³íåöü ãðàô³êè


    free(C);

    if (fclose (outbin) != 0) {
        printf("\n\n\nCannot close a file!!!");
        exit(1);
    }

    return 0;
}




