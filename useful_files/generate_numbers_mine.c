#include <time.h>
#include "push_swap.h"


void generate_array_random_nrs(int *num, int n1, int n2)
{
	int len = n2 - n1 + 1;
	int i;
	int r;
	int temp;

	//Fill array with desired numbers
	for (temp = 0, i = n1; temp < len; i++, temp++)
		num[temp] = i;

	//srand(time(NULL));  //seed rand()

	//Fisher–Yates shuffle algorithm
	for (i = len - 1; i > 0; i--)
	{
		r = rand()%i;   //pop random number
		//swaping using temp
		temp = num[i];
		num[i] = num[r];
		num[r] = temp;
	}
}



int main(int argc, char **argv)
{
	int i;
	int *arr;
	int size_of_array;
	int range_start;
	int range_end;
	int pick;
	int nr_ints_to_generate;

	if (argc != 2)
	{
		printf("Error:  No argument given. \n"
				"  Give 1 argument for 'Number of ints to be generated!\n'");
		return (0);
	}

	range_start = -200;
	range_end = 299;
	nr_ints_to_generate = ft_atoi(argv[1]);

	size_of_array = abs(range_start) + abs(range_end) + 1;
	arr = malloc(size_of_array * sizeof(int)); // size of array, number of integers

	//seed rand()
	srand(time(NULL));
	// generated ints in this range
	generate_array_random_nrs(arr, range_start, range_end); 

	i = 0;
	while (i < nr_ints_to_generate)
	{
		if (i == size_of_array)
			break ;
		printf("%4d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (0);
}

