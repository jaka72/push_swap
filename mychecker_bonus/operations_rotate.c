/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_rotate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 17:52:29 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/26 14:31:13 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

// last becomes first
void	reverse_rotate_b(int *box_b)
{
	int	i;
	int	temp;

	i = t_count.box_b;
	temp = box_b[i - 1];
	while (i > 1)
	{
		box_b[i - 1] = box_b[i - 2];
		i--;
	}
	box_b[0] = temp;
	t_oper.rrb++;
}

void	reverse_rotate_a(int *box_a)
{
	int	i;
	int	temp;

	i = t_count.box_a;
	temp = box_a[i - 1];
	while (i > 1)
	{
		box_a[i - 1] = box_a[i - 2];
		i--;
	}
	box_a[0] = temp;
	t_oper.rra++;
}

void	rotate_b(int *box_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = box_b[0];
	while (i < t_count.box_b - 1)
	{
		box_b[i] = box_b[i + 1];
		i++;
	}
	box_b[t_count.box_b - 1] = temp;
	t_oper.rb++;
}

void	rotate_a(int *box_a)
{
	int	i;
	int	temp;

	i = 0;
	temp = box_a[0];
	while (i < t_count.box_a - 1)
	{
		box_a[i] = box_a[i + 1];
		i++;
	}
	box_a[t_count.box_a - 1] = temp;
	t_oper.ra++;
}
