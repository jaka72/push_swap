/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_5_elements.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 13:16:41 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/06 11:37:40 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	get_min(int *min, int *box_a, t_boxes *box)
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

void	get_min_2(int min0, int *min1, int *box_a, t_boxes *box)
{
	int	i;

	i = 0;
	*min1 = box_a[0];
	if (box_a[0] == min0)
		*min1 = box_a[1];
	while (i < box->count.a)
	{
		if (box_a[i] < *min1 && box_a[i] > min0)
			*min1 = box_a[i];
		i++;
	}
}

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
	int	i;
	int	count;

	get_min(&min_0, box_a, box);
	get_min_2(min_0, &min_1, box_a, box);
	i = 0;
	count = box->count.a;
	while (i < count)
	{
		if (box_a[0] != min_0 && box_a[0] != min_1)
			rotate_a(box_a, box);
		else
			push_b(box_a[0], box_a, box_b, box);
		i++;
	}
	if (box->count.b > 1 && box_b[0] < box_b[1])
		swap_b(box_b, box);
	sort_3_elements(argc, box_a, box);
	push_back_to_a(box_a, box_b, 2, box);
	return (0);
}
