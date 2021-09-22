/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_5_elements.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 13:16:41 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/21 09:29:11 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_elements(int argc, int *box_a, int *box_b)
{
	int	i;
	int	min_0;
	int	min_1;
	int	nr_min;

	get_min(box_a, &min_0);
	while (box_a[0] != min_0)
		reverse_rotate_a(box_a);
	push_b(box_a[0], box_a, box_b);
	nr_min = 1;
	if (argc - 1 == 5)
	{
		get_min(box_a, &min_1);
		while (box_a[0] != min_1)
			rotate_a(box_a);
		push_b(box_a[0], box_a, box_b);
		nr_min = 2;
	}
	sort_3_elements(argc, box_a, box_b);
	i = 0;
	while (i < nr_min)
	{
		push_a(box_b[0], box_a, box_b);
		i++;
	}
}
