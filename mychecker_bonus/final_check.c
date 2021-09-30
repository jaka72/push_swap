/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   final_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/26 13:30:58 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/30 13:56:33 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

int	check_if_a_sorted(int *input)
{
	int	i;

	i = 0;
	while (i < t_count.box_a - 1)
	{
		if (input[i] < input[i + 1])
			i++;
		else
			return (-1);
	}
	return (0);
}

int	final_check(struct s_boxes *b)
{
	if (check_if_a_sorted(b->input) == -1)
	{
		ft_putstr("KO\n");
		return (-1);
	}
	if (t_count.box_b != 0)
	{
		ft_putstr("KO\n");
		return (-1);
	}
	else
	{
		ft_putstr("OK\n");
		return (0);
	}
	return (0);
}
