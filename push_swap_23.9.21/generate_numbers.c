
#include "push_swap.h"
#include <time.h>
  
// Generates and prints 'count' random
// numbers in range [lower, upper].
void printRandoms(int lower, int upper, int count)
{
    int i;
    int num;
    int *arr;

    arr = calloc(count, sizeof(int));
    // i = 0;
    // while (i < count)
    // {
    //     //arr[i] = 7;
    //     printf("%d  ", arr[i]);
    //     i++;
    // }
    // printf("\n\n");

    i = 0;
    while (i < count)
    {
        num = (rand() % (upper - lower + 1)) + lower;
        if (arr[num] == 1)
            ;
        else
        {
            arr[num] = 1;
            printf("%d  ", num);
            i++;
        }   
    }
    free(arr);
}
  



int main(void)
{
    // Print numbers from 500 to 1
    // int i;

    // i = 500;
    // while (i > 0)
    // {
    //     //printf("%d ", i);
    //     i--;
    // }


    // Print random numbers in range
    // Current time as random generator
    int lower = 0, upper = 499, count = 500;
    srand(time(0));
    printRandoms(lower, upper, count);

    return (0);
}
