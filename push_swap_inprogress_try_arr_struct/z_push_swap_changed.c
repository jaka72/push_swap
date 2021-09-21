/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   z_push_swap_changed.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 17:50:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/21 11:28:46 by jmurovec      ########   odam.nl         */
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
	t_oper.sa = 0;
	t_oper.sb = 0;
}



////////////////////////////
	// BIG Sorting Push Swap
	////////////////////////////
	// REPEAT pb and ra ON boxA, on each bitplace, times argc-1
	//   ie: if largest number has 5 bitplaces (10110), repeat 5 cycles 
	////printf("\nStart Loop (maxbits:%d, argc:%d)\n", max_nr_bits, argc);
	void	sort_big(int argc, int max_nr_bits, int *longest_nr, int *box_a, int *box_b, int *input_simplified)
	{
		int	i;
		int	j;

		// find longest number
		find_longest_nr(argc, longest_nr, input_simplified);

		// calculate nu of bits in largest number
		find_nr_bits(*longest_nr, &max_nr_bits);

		i = 0;
		while (i < max_nr_bits)
		{
			////printf("\ni%d\n", i);
			j = 0;
			while (j < argc - 1)
			{
				////printf("  a%d[%d] ", 0, box_a[0]);
				if (((box_a[0] >> i) & 1) == 0)
				{
					////printf(MAG"Start push_b()"RES);
					push_b(box_a[0], box_a, box_b);
					////print_box(box_a, t_count.box_a, "box_a:");
					////print_box(box_b, t_count.box_b, "box_b:");
				}
				else
				{
					//printf(YEL"Start rotate_a()"RES);
					rotate_a(box_a);
					////print_box(box_a, t_count.box_a, "box_a:");
					////print_box(box_b, t_count.box_b, "box_b:");
				}
				////printf("------------------------------- end j%d\n\n", j);
				j++;
			}
			//pushback to A, whatever is in B
			while (t_count.box_b > 0)
			{
				////printf(GRN"Start push_a"RES);
				//push_a(box_b[t_count.box_b], box_a, box_b);
				push_a(box_b[0], box_a, box_b);
				////print_box(box_a, t_count.box_a, "box_a:");
				////print_box(box_b, t_count.box_b, "box_b:");
			}
			////printf("  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx end i%d\n", i);
			i++;
		}
		////printf("\n finnal Result SImplified:\n");

		
	}



int main(int argc, char *argv[])
{
	int i;
	int	j;
	int *input;
	int *input_sorted_temp;
	int	*input_simplified;
	int	*finnal;
	int	*box_a;
	int	*box_b;
	int int_temp;
	int	longest_nr;
	int	max_nr_bits;

	input = malloc((argc - 1) * sizeof(int));
	input_sorted_temp = malloc((argc - 1) * sizeof(int));
	input_simplified = malloc((argc - 1) * sizeof(int));
	finnal = malloc((argc - 1) * sizeof(int));
	box_a = malloc((argc - 1) * sizeof(int));
	box_b = malloc((argc - 1) * sizeof(int));

	// copy from argv[] to input[], convert to ints
	copy_args_convert_to_ints(argc, argv, input);

	if (check_if_sorted(argc, input) == 1)
	{
		//printf(YEL"Numbers are already sorted.\n"RES);
		return (0);
	}

	reset_all(argc);

	// determine number of elements
	if (argc - 1 <= 1)   // zero or only 1 element
	{
		//printf("Error, zero or only 1 element\n");
		return (-1);
	}
	else if (argc - 1 == 2 || argc - 1 == 3)
	{
		//printf(YEL"Found 2 or 3 elements\n"RES);	
		sort_3_elements(argc, box_a, box_b); // little sorting, 3 elements
	}
	else if (argc - 1 == 4 || argc - 1 == 5)
	{
		//printf(YEL"Found 4 or 5 elements\n"RES);	
		sort_5_elements(argc, box_a, box_b); // sorting 5 elements
	}
	else
	{
		//printf(YEL"Found more than 6 elements\n"RES);	

		copy_to_sorted_temp(argc, input, input_sorted_temp);

		// bubble sort into separate array
		bubble_sort(argc, input_sorted_temp);

		// save simplified values to separate array
		store_to_simplyfied(argc, input, input_sorted_temp, input_simplified);

		sort_big(argc, max_nr_bits, &longest_nr, box_a, box_b, input_simplified);
		

		// copy from simplified input to box_a
		i = 0;
		while (i < argc - 1)
		{
			box_a[i] = input_simplified[i];
			i++;
		}
		box_a = input_simplified;
	}

	// copy_to_sorted_temp(argc, input, input_sorted_temp);

	// // bubble sort into separate array
	// bubble_sort(argc, input_sorted_temp);

	// // save simplified values to separate array
	// store_to_simplyfied(argc, input, input_sorted_temp, input_simplified);

	// // find longest number
	// find_longest_nr(argc, &longest_nr, input_simplified);


	// // calculate nu of bits in largest number
	// find_nr_bits(longest_nr, &max_nr_bits);


	// // copy from simplified input to box_a
	// i = 0;
	// while (i < argc - 1)
	// {
	// 	box_a[i] = input_simplified[i];
	// 	i++;
	// }
	// //box_a = input_simplified;


	/////////////////////////////////////////////////////////////////////////////////////////////

	

	////print_box(box_a, t_count.box_a, "box_a");





	



	t_oper.all = t_oper.pa + t_oper.pb + t_oper.ra + t_oper.sa;
	//printf(GRN"  pa:%d, pb:%d, ra:%d, sa:%d, ALL:%d\n"RES,
		t_oper.pa, t_oper.pb, t_oper.ra, t_oper.sa, t_oper.all);

	//print_box(box_a, t_count.box_a, "box_a:");


	// COPY ORIG VALUES INTO finnal SORTED ARRAY
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (input_simplified[j] == i)
				finnal[i] = input[j];
			j++;
		}
		i++;
	}
	//printf("\n Simplified input:");
	//print_box(input_simplified, argc - 1, "");

	//printf("\n finnal Result Original Values:\n");
	//print_box(finnal, argc - 1, "");
	////print_box(box_a, argc - 1, "");


	return (0);
}