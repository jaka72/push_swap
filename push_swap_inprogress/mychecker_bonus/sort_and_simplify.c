/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_and_simplify.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:44:24 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/22 13:09:52 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_longest_nr(int argc, int *input_simplified)
{
	int	i;

	i = 1;
	t_data.longest_nr = abs(input_simplified[0]);
	while (i < argc - 1)
	{
		if (t_data.longest_nr < abs(input_simplified[i]))
			t_data.longest_nr = abs(input_simplified[i]);
		i++;
	}
}

// save simplified values to separate array
void	store_to_simplyfied(int argc, int *input,
	int *input_sorted_temp, int *input_simplified)
{
	int	i;
	int	j;

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
}

void	bubble_sort(int argc, int *input_sorted_temp)
{
	int	i;
	int	j;
	int	temp;

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
}

// copy input into sorted_temp
void	copy_to_sorted_temp(int argc, int *input, int *input_sorted_temp)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		input_sorted_temp[i] = input[i];
		i++;
	}
}

// copy from argv[] to input[], convert to ints
void	copy_args_convert_to_ints(int argc, char *argv[], int *input)
{
	int	i;
	int	temp;

	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(argv[i]);
		// maybe here:
		// if (temp == -1)    // it was overflow, number too big
		//		return (-1); 
		input[i - 1] = temp;
		i++;
	}
}
