/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_elements.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 12:29:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/29 12:35:27 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_sa_rra(int *box_a, t_boxes *box)
{
	rotate_a(box_a, box);
	swap_a(box_a, box);
	reverse_rotate_a(box_a, box);
}

int	sort_3_elements(int argc, int *box_a, t_boxes *box)
{
	int	max;
	int	min;

	if (argc - 1 == 2)
	{
		swap_a(box_a, box);
		return (0);
	}
	get_min(&min, box_a, box);
	get_max(argc, &max, box_a);
	if (box_a[0] == min && box_a[1] == max)
		ra_sa_rra(box_a, box);
	else if (box_a[1] == min && box_a[2] == max)
		swap_a(box_a, box);
	else if (box_a[1] == max && box_a[2] == min)
		reverse_rotate_a(box_a, box);
	else if (box_a[0] == max && box_a[1] == min)
		rotate_a(box_a, box);
	else if (box_a[0] == max && box_a[2] == min)
	{
		swap_a(box_a, box);
		reverse_rotate_a(box_a, box);
	}
	return (0);
}
