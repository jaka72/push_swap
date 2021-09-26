/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initial_check_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/26 11:43:30 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/26 11:44:18 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				ft_putstr("Error\n");
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
