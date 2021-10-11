/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_rotate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 17:52:29 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/06 11:38:54 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// last becomes first
void	reverse_rotate_b(int *box_b, t_boxes *box)
{
	int	i;
	int	temp;

	i = box->count.b;
	temp = box_b[i - 1];
	while (i > 1)
	{
		box_b[i - 1] = box_b[i - 2];
		i--;
	}
	box_b[0] = temp;
	box->count.rrb++;
	ft_putstr("rrb\n");
}

// last becomes first
void	reverse_rotate_a(int *box_a, t_boxes *box)
{
	int	i;
	int	temp;

	i = box->count.a;
	temp = box_a[i - 1];
	while (i > 1)
	{
		box_a[i - 1] = box_a[i - 2];
		i--;
	}
	box_a[0] = temp;
	box->count.rra++;
	ft_putstr("rra\n");
}

void	rotate_b(int *box_b, t_boxes *box)
{
	int	i;
	int	temp;

	i = 0;
	temp = box_b[0];
	while (i < box->count.b - 1)
	{
		box_b[i] = box_b[i + 1];
		i++;
	}
	box_b[box->count.b - 1] = temp;
	box->count.rb++;
	ft_putstr("rb\n");
}

void	rotate_a(int *box_a, t_boxes *box)
{
	int	i;
	int	temp;

	i = 0;
	temp = box_a[0];
	while (i < box->count.a - 1)
	{
		box_a[i] = box_a[i + 1];
		i++;
	}
	box_a[box->count.a - 1] = temp;
	box->count.ra++;
	ft_putstr("ra\n");
}
