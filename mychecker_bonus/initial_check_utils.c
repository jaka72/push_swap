/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initial_check_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/26 13:51:26 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/29 13:25:31 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

int	error(int r, char *msg)
{
	ft_putstr(msg);
	return (r);
}

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
