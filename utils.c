/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 13:46:44 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/26 11:27:00 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_all(int argc, struct s_boxes *box)
{
	box->count.a = argc - 1;
	box->count.b = 0;
	box->count.pb = 0;
	box->count.pa = 0;
	box->count.ra = 0;
	box->count.rra = 0;
	box->count.sa = 0;
	box->count.sb = 0;
}

int	error(int r, char *msg)
{
	ft_putstr(msg);
	return (r);
}

void	find_nr_bits(struct s_boxes *box)
{
	box->data.max_nr_bits = 0;
	while (box->data.longest_nr != 0)
	{
		box->data.longest_nr = box->data.longest_nr >> 1;
		(box->data.max_nr_bits)++;
	}
}

void	get_max(int argc, int *max, int *box_a)
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

void	get_min(int *min, int *box_a, struct s_boxes *box)
{
	int	i;

	i = 1;
	*min = box_a[0];
	while (i < box->count.a)
	{
		if (*min > box_a[i])
			*min = box_a[i];
		i++;
	}
}
