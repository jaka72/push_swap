/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_push.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/18 12:53:10 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/26 14:31:07 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

void	refresh_a(int *box_a)
{
	int	i;

	i = 0;
	while (i < t_count.box_a)
	{
		box_a[i] = box_a[i + 1];
		i++;
	}
}

void	refresh_b(int *box_b)
{
	int	i;

	i = 0;
	while (i < t_count.box_b)
	{
		box_b[i] = box_b[i + 1];
		i++;
	}
}

void	push_a(int b, int *box_a, int *box_b)
{
	int	i;

	if (t_count.box_b == 0)
		return ;
	i = t_count.box_a;
	while (i > 0)
	{
		box_a[i] = box_a[i - 1];
		i--;
	}
	box_a[0] = b;
	t_count.box_a++;
	t_count.box_b--;
	t_oper.pa++;
	refresh_b(box_b);
}

void	push_b(int a, int *box_a, int *box_b)
{
	int	i;

	if (t_count.box_a < 1)
		return ;
	i = t_count.box_b;
	while (i > 0)
	{
		box_b[i] = box_b[i - 1];
		i--;
	}
	box_b[0] = a;
	t_count.box_a--;
	t_count.box_b++;
	t_oper.pb++;
	refresh_a(box_a);
}
