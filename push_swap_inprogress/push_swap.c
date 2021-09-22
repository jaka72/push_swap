/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 17:50:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/22 18:24:00 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(struct s_boxes *b)
{
	free(b->input);
	free(b->input_sorted_temp);
	free(b->input_simplified);
	free(b->finnal);
	free(b->box_a);
	free(b->box_b);
}

int	allocate_all_boxes(int argc, struct s_boxes *b)
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
	t_box	b;

	if (initial_check(argc, argv, &b) == -1)
		return (-1);
	if (allocate_all_boxes(argc, &b) == -1)
		return (-1);
	if (argc - 1 == 2 || argc - 1 == 3)
		return (sort_3_elements(argc, b.input, b.box_b));
	else if (argc - 1 == 4 || argc - 1 == 5)
		return (sort_5_elements(argc, b.input, b.box_b));
	else
		sort_5plus_elements(argc, &b);
	t_oper.all = t_oper.pa + t_oper.pb + t_oper.ra + t_oper.sa + t_oper.rra;


	printf("Final box:\n");
	print_box(b.finnal, t_count.box_a, "before rra");


	free_all(&b);
	
	// system("leaks push_swap");
	// while (1)  // not necessary
	// { ; }
	
	return (0);
}
