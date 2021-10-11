/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 13:46:44 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/05 14:15:11 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_all(int argc, t_boxes *box)
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

void	find_nr_bits(t_boxes *box)
{
	box->data.max_nr_bits = 0;
	while (box->data.longest_nr != 0)
	{
		box->data.longest_nr = box->data.longest_nr >> 1;
		(box->data.max_nr_bits)++;
	}
}
