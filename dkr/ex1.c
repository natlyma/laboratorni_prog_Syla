#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int N = 1;
    double sum = 2;
    printf("Enter N(>=1)\nN = ");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    if (i % 2)
        sum += -i/i+1;
    else
        sum += i/i+1;
    printf("Sum = %lf", sum);
    getch();
    return 0;
}