/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_elements.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 12:29:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/26 14:31:22 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

void	pb_sa_pa(int a0, int b0, int *box_a, int *box_b)
{
	push_b(a0, box_a, box_b);
	swap_a(box_a);
	push_a(b0, box_a, box_b);
}

int	sort_3_elements(int argc, int *box_a, int *box_b)
{
	int	max;
	int	min;

	if (argc - 1 == 2)
		return (swap_a(box_a));
	get_min(box_a, &min);
	get_max(argc, box_a, &max);
	if (box_a[0] == min && box_a[1] == max)
		pb_sa_pa(box_a[0], box_b[0], box_a, box_b);
	else if (box_a[1] == min && box_a[2] == max)
		swap_a(box_a);
	else if (box_a[1] == max && box_a[2] == min)
	{
		swap_a(box_a);
		rotate_a(box_a);
		swap_a(box_a);
	}
	else if (box_a[0] == max && box_a[1] == min)
		rotate_a(box_a);
	else if (box_a[0] == max && box_a[2] == min)
	{
		swap_a(box_a);
		reverse_rotate_a(box_a);
	}
	return (0);
}
