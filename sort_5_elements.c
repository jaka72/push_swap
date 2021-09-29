/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_5_elements.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 13:16:41 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/29 12:35:33 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(int *box_a, int *box_b, int nr_min, t_boxes *box)
{
	int	i;

	i = 0;
	while (i < nr_min)
	{
		push_a(box_b[0], box_a, box_b, box);
		i++;
	}
}

int	sort_5_elements(int argc, int *box_a, int *box_b, t_boxes *box)
{
	int	min_0;
	int	min_1;
	int	nr_min;

	get_min(&min_0, box_a, box);
	while (box_a[0] != min_0)
		reverse_rotate_a(box_a, box);
	push_b(box_a[0], box_a, box_b, box);
	nr_min = 1;
	if (argc - 1 == 5)
	{
		get_min(&min_1, box_a, box);
		while (box_a[0] != min_1)
			rotate_a(box_a, box);
		push_b(box_a[0], box_a, box_b, box);
		nr_min = 2;
	}
	sort_3_elements(argc, box_a, box);
	push_back_to_a(box_a, box_b, nr_min, box);
	return (0);
}
