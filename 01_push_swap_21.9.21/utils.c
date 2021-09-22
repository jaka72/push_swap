/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 13:46:44 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/20 18:03:51 by jmurovec      ########   odam.nl         */
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

void get_max(int argc, int *box_a, int *max)
{
    int i;
    
    i = 1;
	*max = box_a[0];
	while (i < argc - 1)
	{
		if (*max < box_a[i])
			*max = box_a[i];
		i++;
	}
	//printf("\nFound largest number:  %d\n", *max);
}

void get_min(int *box_a, int *min)
{
    int i;

	////printf("\nFind min in box a, count: %d\n", t_count.box_a);
    i = 1;
	*min = box_a[0];
	while (i < t_count.box_a)
	{
		if (*min > box_a[i])
			*min = box_a[i];
		i++;
	}
	//printf("\nFound smallest number: %d", *min);
}

int		check_identical_elements(int argc, int *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (input[i] == input[j])
			{
				printf("Error\n There are 2 identical elements i%d[%d]  j%d[%d]\n", i, input[i], j, input[j]);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_sorted(int argc, int *input)
{
	int i;

	i = 0;
	while (i < argc - 2)
	{
		if (input[i] < input[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

