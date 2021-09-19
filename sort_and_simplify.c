/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_and_simplify.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:44:24 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/19 15:40:15 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_nr_bits(int longest_nr, int *max_nr_bits)
{
    *max_nr_bits = 0;
	//longest_nr = 7;
	while (longest_nr != 0)
	{
		longest_nr = longest_nr>>1;
		(*max_nr_bits)++;
		//////printf("   longest>>1: %d,", longest_nr);
	}
	////printf("Find max nr of bits: %d\n", *max_nr_bits);
	////printf("\n///////////////////////////////////////////\n");
}

	
void find_longest_nr(int argc, int *longest_nr, int *input_simplified)
{
    int i;
    
    i = 1;
	*longest_nr = abs(input_simplified[0]);
	while (i < argc - 1)
	{
		if (*longest_nr < abs(input_simplified[i]))
			*longest_nr = abs(input_simplified[i]);
		i++;
	}
	////printf("\nFind longest number: %d\n", *longest_nr);
}


// save simplified values to separate array
void store_to_simplyfied(int argc, int *input, int *input_sorted_temp, int *input_simplified)
{
    int i;
    int j;
    
	////printf("\nStore to Simplified array");
    j = 0;
	while (j < argc - 1)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (input_sorted_temp[j] == input[i])
				input_simplified[i] = j;
			i++;
		}
		j++;
	}
	//print_box(input_simplified, argc - 1, "Simplified_input, Original order");
}


void bubble_sort(int argc, int *input_sorted_temp)
{
    int i;
    int j;
    int temp;
	
	////printf("\nStart bubble sort:");
    j = 0;
	while (j < argc - 1)
	{
		i = 0;
		while (i < argc - 2)
		{
			if (input_sorted_temp[i] > input_sorted_temp[i + 1])
			{
				temp = input_sorted_temp[i];
				input_sorted_temp[i] = input_sorted_temp[i + 1];
				input_sorted_temp[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
	////print_box(input_sorted_temp, argc - 1, "Input_sorted_temp");
}


// copy input into sorted_temp
void copy_to_sorted_temp(int argc, int *input, int *input_sorted_temp)
{
    int i;

	////printf("argc: %d", argc - 1);
    i = 0;
	while (i < argc - 1)
	{
		input_sorted_temp[i] = input[i];
		i++;
	}
	////print_box(input_sorted_temp, argc - 1, "Input_sorted_temp");
}

// copy from argv[] to input[], convert to ints
void	copy_args_convert_to_ints(int argc, char *argv[], int *input)
{
    int i;
    int temp;

	////printf("Copy from argv[], convert to ints:\n");
    i = 1;
	while (i < argc)
	{
		////printf("  argv[%d]:%s,", i, argv[i]);
		temp = ft_atoi(argv[i]);
		input[i - 1] = temp;
//		////printf("input[%d]:%d\n", i - 1, input[i - 1]);
		i++;
	}
    ////printf("\n\n");
}
