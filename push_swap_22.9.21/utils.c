/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 13:46:44 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/21 10:09:08 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_nr_bits(void)
{
	t_data.max_nr_bits = 0;
	while (t_data.longest_nr != 0)
	{
		t_data.longest_nr = t_data.longest_nr >> 1;
		(t_data.max_nr_bits)++;
	}
}

void	get_max(int argc, int *box_a, int *max)
{
	int	i;

	i = 1;
	*max = box_a[0];
	while (i < argc - 1)
	{
		if (*max < box_a[i])
			*max = box_a[i];
		i++;
	}
}

void	get_min(int *box_a, int *min)
{
	int	i;

	i = 1;
	*min = box_a[0];
	while (i < t_count.box_a)
	{
		if (*min > box_a[i])
			*min = box_a[i];
		i++;
	}
}

int	check_identical_elements(int argc, int *input)
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
				printf("Error\n There are 2 identical \
					elements i%d[%d]  j%d[%d]\n",
					i, input[i], j, input[j]);
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
	int	i;

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
