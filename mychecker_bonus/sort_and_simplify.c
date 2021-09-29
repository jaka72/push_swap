/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_and_simplify.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:44:24 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/29 13:25:36 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

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
int	copy_args_convert_to_ints(int argc, char *argv[], int *input)
{
	int	i;
	int	temp;
	int	flag_overflow;

	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(argv[i], &flag_overflow);
		input[i - 1] = temp;
		i++;
		if (flag_overflow == 1)
		{
			ft_putstr("Error\n");
			return (-1);
		}
	}
	return (0);
}
