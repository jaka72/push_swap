#include <time.h>
#include "../push_swap.h"

static int	overflow(int sign, int num, const char *str, int i)
{	
	if (sign == -1 && str[i] > '8')
		return (-1);
	if (sign == -1 && num > 214748364)
		return (-1);
	if (sign == 1 && str[i] > '7')
		return (-1);
	if (sign == 1 && num > 214748364)
		return (-1);
	else
	{
		num = (num * 10) + (str[i] - '0');
		return (num * sign);
	}
}

void	check_sign(int *i, const char *str, int *sign)
{
	while (str[*i] == ' ' || (str[*i] >= '\t' && str[*i] <= '\r'))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int	ft_atoi_2(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;

	check_sign(&i, str, &sign);
	num = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (num >= 214748364)
		{
			if (overflow(sign, num, str, i) == -1)
			{
				return (-1);
			}
		}
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}




///////////////




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
	nr_ints_to_generate = ft_atoi_2(argv[1]);

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
