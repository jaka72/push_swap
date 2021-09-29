/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_5plus_elements.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 12:59:34 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/29 12:35:37 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_orig_values_to_sorted_finnal(int argc, int *input,
	int *input_simplified, int *finnal)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (input_simplified[j] == i)
				finnal[i] = input[j];
			j++;
		}
		i++;
	}
}

// REPEAT pb and ra ON boxA, on each bitplace, times argc-1
//   ie: if largest number has 5 bitplaces (10110), repeat 5 cycles 
////printf("\nStart Loop (maxbits:%d, argc:%d)\n", max_nr_bits, argc);
void	big_sort(int argc, int *box_a, int *box_b, t_boxes *box)
{
	int	i;
	int	j;

	i = 0;
	while (i < box->data.max_nr_bits)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (((box_a[0] >> i) & 1) == 0)
				push_b(box_a[0], box_a, box_b, box);
			else
				rotate_a(box_a, box);
			j++;
		}
		while (box->count.b > 0)
			push_a(box_b[0], box_a, box_b, box);
		i++;
	}
}

int	sort_5plus_elements(int argc, struct s_boxes *b)
{
	int	i;

	copy_to_sorted_temp(argc, b->input, b->input_sorted_temp);
	bubble_sort(argc, b->input_sorted_temp);
	store_to_simplyfied(argc, b->input, b->input_sorted_temp,
		b->input_simplified);
	find_longest_nr(argc, b->input_simplified, b);
	find_nr_bits(b);
	i = 0;
	while (i < argc - 1)
	{
		b->box_a[i] = b->input_simplified[i];
		i++;
	}
	big_sort(argc, b->box_a, b->box_b, b);
	copy_orig_values_to_sorted_finnal(argc, b->input, b->input_simplified,
		b->finnal);
	return (0);
}
