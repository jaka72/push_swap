/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_and_simplify.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:44:24 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/07 14:47:00 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_longest_nr(int argc, int *input_simplified, t_boxes *box)
{
	int	i;

	i = 1;
	box->data.longest_nr = abs(input_simplified[0]);
	while (i < argc - 1)
	{
		if (box->data.longest_nr < abs(input_simplified[i]))
			box->data.longest_nr = abs(input_simplified[i]);
		i++;
	}
}

// Where input[] is the same as sorted[], 
//    it becomes 0,1,2,3 ... in simplified[ ]
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

int	copy_args_convert_to_ints(int *argc, char *argv[], int *input)
{
	int	i;
	int	temp;
	int	flag_overflow;

	i = 1;
	while (i < *argc)
	{
		if (ft_strlen(argv[i]) != 0)
		{
			temp = ft_atoi(argv[i], &flag_overflow);
			input[i - 1] = temp;
		}
		else
			return (error(-1, "Error\n"));
		i++;
		if (flag_overflow == 1)
		{
			ft_putstr("Error\n");
			return (-1);
		}
	}
	return (0);
}
