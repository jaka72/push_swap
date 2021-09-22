/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 17:50:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/21 10:11:52 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FIRST ELEMENT IN THE ARRAY IS ON THE TOP OF THE STACK
void	reset_all(int argc)
{
	t_count.box_a = argc - 1;
	t_count.box_b = 0;
	t_oper.pb = 0;
	t_oper.pa = 0;
	t_oper.ra = 0;
	t_oper.rra = 0;
	t_oper.sa = 0;
	t_oper.sb = 0;
}

void	copy_orig_values_to_sorted_final(int argc, int *input, int *input_simplified, int *final)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (input_simplified[j] == i)
				final[i] = input[j];
			j++;
		}
		i++;
	}
}

void	big_sort(int argc, int *box_a, int *box_b)
{
	int	i;
	int	j;

	// REPEAT pb and ra ON boxA, on each bitplace, times argc-1
	//   ie: if largest number has 5 bitplaces (10110), repeat 5 cycles 
	////printf("\nStart Loop (maxbits:%d, argc:%d)\n", max_nr_bits, argc);
	i = 0;
	while (i < t_data.max_nr_bits)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (((box_a[0] >> i) & 1) == 0)
				push_b(box_a[0], box_a, box_b);
			else
				rotate_a(box_a);
			j++;
		}
		//push back to A, whatever is in B
		while (t_count.box_b > 0)
			push_a(box_b[0], box_a, box_b);
		i++;
	}
}

int	check_if_all_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while(i < argc - 1)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Error\n Argument isn't numeric.\n");
				printf("Error\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int i;
	int *input;
	int *input_sorted_temp;
	int	*input_simplified;
	int	*final;
	int	*box_a;
	int	*box_b;

	if (argc - 1 <= 1)
		return (-1);
	if (check_if_all_numeric(argc, argv) < 0)
		return (-1);
	input = malloc((argc - 1) * sizeof(int));
	
	// copy from argv[] to input[], convert to ints
	copy_args_convert_to_ints(argc, argv, input);

	//print_box(input, argc - 1, "Copied from args to box 'input'");

	// check identical elements
	if (check_identical_elements(argc, input) < 0)
	{
		free(input);
		return (-1);
	}
	if (check_if_sorted(argc, input) == 1)
	{
		//printf("Numbers are already sorted.\n");
		free(input);
		return (0);
	}
	reset_all(argc);

	input_sorted_temp = malloc((argc - 1) * sizeof(int));
	input_simplified = malloc((argc - 1) * sizeof(int));
	final = malloc((argc - 1) * sizeof(int));
	box_a = malloc((argc - 1) * sizeof(int));
	box_b = malloc((argc - 1) * sizeof(int));


	// determine number of elements
	if (argc - 1 == 2 || argc - 1 == 3)
	{
		//printf(YEL"Found 2 or 3 elements, argc: %d\n"RES, argc);
		//printf(YEL"   0[%s],  1[%s],  2[%s],   3[%s]\n"RES, argv[0], argv[1], argv[2], argv[3]);
		sort_3_elements(argc, input, box_b); // little sorting, 3 elements
		return (0);
		//print_box(input, argc - 1, "Final box_a");
	}
	else if (argc - 1 == 4 || argc - 1 == 5)
	{
		//printf(YEL"Found 4 or 5 elements\n"RES);	
		sort_5_elements(argc, input, box_b); // sorting 5 elements
		return (0);
		//print_box(input, argc - 1, "Final box_a");
	}
	else
	{
		//printf(YEL"--- Found more than 5 elements --- \n"RES);
		copy_to_sorted_temp(argc, input, input_sorted_temp);
		//print_box(input_sorted_temp, argc - 1, "Box Input_sorted_temp - before sorting");

		// bubble sort into separate array, THIS WILL WAIT UNTIL THE END
		// BECAUSE IT HAS THE ORIGINAL ORDER ??? 
		bubble_sort(argc, input_sorted_temp);
		//print_box(input_sorted_temp, argc - 1, "Box Input_sorted_temp - after sorting");
		
		// save simplified values to separate array
		store_to_simplyfied(argc, input, input_sorted_temp, input_simplified);

		// find longest number
		find_longest_nr(argc, input_simplified);
		// calculate nu of bits in largest number
		find_nr_bits();

		// copy from simplified input to box_a
		i = 0;
		while (i < argc - 1)
		{
			box_a[i] = input_simplified[i];
			i++;
		}

		big_sort(argc, box_a, box_b);
		copy_orig_values_to_sorted_final(argc, input, input_simplified, final);

	}

	t_oper.all = t_oper.pa + t_oper.pb + t_oper.ra + t_oper.sa + t_oper.rra;

	free(input);
	free(input_sorted_temp);
	free(input_simplified);
	free(final);
	free(box_a);
	free(box_b);

	return (0);
}