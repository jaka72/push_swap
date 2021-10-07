/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 17:50:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/06 13:23:42 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_boxes *b)
{
	free(b->input);
	free(b->input_sorted_temp);
	free(b->input_simplified);
	free(b->finnal);
	free(b->box_a);
	free(b->box_b);
}

int	allocate_all_boxes(int argc, t_boxes *b)
{
	b->input_sorted_temp = malloc((argc - 1) * sizeof(int));
	b->input_simplified = malloc((argc - 1) * sizeof(int));
	b->finnal = malloc((argc - 1) * sizeof(int));
	b->box_a = malloc((argc - 1) * sizeof(int));
	b->box_b = malloc((argc - 1) * sizeof(int));
	if (!b->input_sorted_temp || !b->input_simplified)
		return (-1);
	if (!b->finnal || !b->box_a || !b->box_b)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_boxes	b;

	if (initial_check(&argc, argv, &b) == -1)
		return (-1);
	if (allocate_all_boxes(argc, &b) == -1)
		return (-1);
	if (argc - 1 == 2 || argc - 1 == 3)
	{
		sort_3_elements(argc, b.input, &b);
		free_all(&b);
		return (0);
	}
	else if (argc - 1 == 4 || argc - 1 == 5)
	{
		sort_5_elements(argc, b.input, b.box_b, &b);
		free_all(&b);
		return (0);
	}
	else
	{
		sort_5plus_elements(argc, &b);
		free_all(&b);
		return (0);
	}
	return (0);
}
