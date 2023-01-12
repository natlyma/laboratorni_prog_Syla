#include <conio.h>
#include <stdio.h>

#define ARR_SIZE 5

int searching(int *arr, const int size);
int main()
{
    int arr[5] = {1,2,10,7,5};
    printf("Num of searching numeric is %d", searching(&arr[0], ARR_SIZE));
    getch();
}

int searching(int *arr, const int size)
{
    int nums = 0;
    for (int i = 0; i < size; i++)
    {
         if (arr[i] == 2 || arr[i] == 5 || arr[i] == 7 || arr[i] == 10)
                nums++;
    }
    return nums;
}