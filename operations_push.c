/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_push.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/18 12:53:10 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/26 14:22:57 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_a(int *box_a, struct s_boxes *box)
{
	int	i;

	i = 0;
	while (i < box->count.a)
	{
		box_a[i] = box_a[i + 1];
		i++;
	}
}

void	refresh_b(int *box_b, struct s_boxes *box)
{
	int	i;

	i = 0;
	while (i < box->count.b)
	{
		box_b[i] = box_b[i + 1];
		i++;
	}
}

void	push_a(int b, int *box_a, int *box_b, struct s_boxes *box)
{
	int	i;

	if (box->count.b == 0)
		return ;
	i = box->count.a;
	while (i > 0)
	{
		box_a[i] = box_a[i - 1];
		i--;
	}
	box_a[0] = b;
	box->count.a++;
	box->count.b--;
	box->count.pa++;
	ft_putstr("pa\n");
	refresh_b(box_b, box);
}

void	push_b(int a, int *box_a, int *box_b, struct s_boxes *box)
{
	int	i;

	if (box->count.a < 1)
		return ;
	i = box->count.b;
	while (i > 0)
	{
		box_b[i] = box_b[i - 1];
		i--;
	}
	box_b[0] = a;
	box->count.a--;
	box->count.b++;
	box->count.pb++;
	ft_putstr("pb\n");
	refresh_a(box_a, box);
}
