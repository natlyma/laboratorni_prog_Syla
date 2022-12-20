#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void swap(int *a, int *b);
void array_fill(int **array, int x_size, int y_size);
void array_print(int **array, int x_size, int y_size);
void array_erase(int **array, int x_size);
void maximum_minimum(int **A, int A_size, int *maximum_a, int *minimum_a);
int **array_transposition(int **B, int n_b, int m_b);
int **array_multiplycate(int **A, int A_size, int **B, int B_rows, int B_columns);
void array_sorting(int **A, int A_size, int row);
int array_sum(int **A, int A_size, int **B, int B_rows, int B_columns);

#define variant 19 // Natal`a

int main()
{
    int minimum_a, maximum_a, method;
    const int A_size = variant, B_rows = variant;
    int B_columns = 0;
    char repeat;

    printf("columns = ");
    scanf("%d", &B_columns);
    printf("\n\n");

    int **A = (int **)malloc(sizeof(int *) * A_size);
    for (int i = 0; i < A_size; i++)
        A[i] = (int *)malloc(sizeof(int) * A_size);
    int **B = (int **)malloc(sizeof(int *) * B_rows);
    for (int i = 0; i < B_rows; i++)
        B[i] = (int *)malloc(sizeof(int) * B_columns);
    int **C;

    array_fill(A, A_size, A_size);
    array_print(A, A_size, A_size);

    array_fill(B, B_rows, B_columns);
    array_print(B, B_rows, B_columns);

    printf("1|minimum maximum\n2|transposition\n3|multiplycate\n4|sorting\n5|sum\nChoose method ");
    scanf("%d", &method);

    switch (method)
    {
    case 1:
        maximum_minimum(A, A_size, &minimum_a, &maximum_a);
        printf("minimum and maximum number, lower than main diagonal\nmin = %d; maximum = %d\n", minimum_a, maximum_a);
    break;
    case 2:
        C = array_transposition(B, B_rows, B_columns);
        array_print(C, B_columns, B_rows);
        array_erase(C, B_columns);
    break;
    case 3:
        C = array_multiplycate(A, A_size, B, B_rows, B_columns);
        array_print(C, B_rows, B_columns);
        array_erase(C, B_rows);
    break;
    case 4:
        printf("enter row for sorting, or \"0\", for sorting matrix ");
        scanf("%d", &method);
        array_sorting(A, A_size, method);
        array_print(A, A_size, A_size);
    break;
    case 5:
        printf("total_sum = %d\n", array_sum(A, A_size, B, B_rows, B_columns));
    break;
    }

    array_erase(A, A_size);
    array_erase(B, B_rows);
    printf("enter \"f\" for finish programm, or \"r\", for repeat all ");
    scanf("%s", &repeat);
    if (repeat == 'r')
        return main();
    getch();
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void array_fill(int **array, int x_size, int y_size)
{
    for (int i = 0; i < x_size; i++)
        for (int j = 0; j < y_size; j++)
            array[i][j] = 5 - i * j;
}

void array_print(int **array, int x_size, int y_size)
{
    printf("%2d  ", 0);
    for (int j = 1; j <= y_size; j++)
        printf(" %5d", j);
    printf("\n");
    for (int i = 0; i < x_size; i++)
    {
        printf("%2d||", i + 1);
        for (int j = 0; j < y_size; j++)
            printf(" %5d", array[i][j]);
        printf(" ||\n");
    }
    printf("\n");
}

void array_erase(int **array, int x_size)
{
    for (int i = 0; i < x_size; i++)
        free(array[i]);
    free(array);
}

void maximum_minimum(int **A, int A_size, int *maximum_a, int *minimum_a)
{
    if (A_size > 1)
    {
        *maximum_a = *minimum_a = A[1][0];
        for (int i = 2; i < A_size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (A[i][j] < *minimum_a)
                    *maximum_a = A[i][j];
                else if (A[i][j] > *minimum_a)
                    *maximum_a = A[i][j];
            }
        }
    }
    else
        printf("WRONG MATRIX");
}

int **array_transposition(int **B, int B_rows, int B_columns)
{
    int C_rows = B_columns, C_columns = B_rows;
    int **C = (int **)malloc(sizeof(int *) * C_rows);
    for (int i = 0; i < C_rows; i++)
        C[i] = (int *)malloc(sizeof(int) * C_columns);
    for (int i = 0; i < C_rows; i++)
        for (int j = 0; j < C_columns; j++)
            C[i][j] = B[j][i];
    return C;
}

int **array_multiplycate(int **A, int A_size, int **B, int B_rows, int B_columns)
{
    if (A_size == B_rows)
    {
        int C_rows = A_size, C_columns = B_columns;
        int **C = (int **)malloc(sizeof(int *) * C_rows);
        for (int i = 0; i < C_rows; i++)
            C[i] = (int *)malloc(sizeof(int) * C_columns);

        for (int i = 0; i < C_rows; i++)
            for (int j = 0; j < C_columns; j++)
                C[i][j] = 0;

        for (int i = 0; i < C_rows; i++)
            for (int j = 0; j < C_columns; j++)
                for (int t = 0; t < A_size; t++)
                    C[i][j] += A[i][t] * B[t][j];
        return C;
    }
    else
    {
        printf("ne uzgodzheno\n");
        return 0;
    }
}

void array_sorting(int **A, int A_size, int row)
{
    printf("\n\n");
    if (row == 0)
    {
        int minimum_num = A[0][0], *minimum_pointer = &A[0][0];
        for (int i = 0; i < A_size; i++)
            for (int j = 0; j < A_size; j++)
            {
                minimum_num = A[i][j];
                minimum_pointer = &A[i][j];
                for (int ii = i, jj = j; ii < A_size; ii++, jj = 0)
                    for (jj; jj < A_size; jj++)
                        if (A[ii][jj] < minimum_num)
                        {
                            minimum_num = A[ii][jj];
                            minimum_pointer = &A[ii][jj];
                        }
                swap(&A[i][j], minimum_pointer);
            }
    }
    else
    {
        int minimum_num = A[row - 1][0], *minimum_pointer = &A[row - 1][0];
        for (int j = 0; j < A_size; j++)
        {
            minimum_num = A[row - 1][j];
            minimum_pointer = &A[row - 1][j];
            for (int jj = j; jj < A_size; jj++)
                if (A[row - 1][jj] < minimum_num)
                {
                    minimum_num = A[row - 1][jj];
                    minimum_pointer = &A[row - 1][jj];
                }
            swap(&A[row - 1][j], minimum_pointer);
        }
    }
}

int array_sum(int **A, int A_size, int **B, int B_rows, int B_columns)
{
    int total_sum = 0;
    for (int i = 0; i < A_size; i++)
        for (int j = 0; j < A_size; j++)
            total_sum += A[i][j];
    for (int j = 0; j < B_columns; j++)
        for (int i = 0; i < B_rows; i++)
            total_sum += B[i][j];
    return total_sum;
}