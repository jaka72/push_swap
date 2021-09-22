/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_elements.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 12:29:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/20 18:03:54 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    sort_3_elements(int argc, int *box_a, int *box_b)
{
	//int	i;
	int	max;
	int	min;

	//print_box(box_a, t_count.box_a, "At start of sort 3");

	// in case just 2 elements
	if (argc - 1 == 2)
	{
		//printf(YEL"--- found 2 elements, only swap !--- \n"RES);
		swap_a(box_a);
		return ;
	}

	get_min(box_a, &min);
	get_max(argc, box_a, &max);

	//i = 0;
	if (box_a[0] == min && box_a[1] == max)
	{
        //printf(RED"   a)\n"RES);
		push_b(box_a[0], box_a, box_b);
		swap_a(box_a);
		push_a(box_b[0], box_a, box_b);
	}
	else if (box_a[1] == min && box_a[2] == max)
	{
        //printf(RED"   b)\n"RES);
		swap_a(box_a);
	}
	else if (box_a[1] == max && box_a[2] == min)
	{
		//printf(RED"   c)\n"RES);
		swap_a(box_a);
		rotate_a(box_a);
		swap_a(box_a);
		//print_box(box_a, t_count.box_a, "after sa");
	}
	else if (box_a[0] == max && box_a[1] == min)
	{
        //printf(RED"   d)\n"RES);
		rotate_a(box_a);
		//print_box(box_a, t_count.box_a, "  after ra");
	}
	else if (box_a[0] == max && box_a[2] == min)
	{
        //printf(RED"   e)\n"RES);
		swap_a(box_a);
		//print_box(box_a, t_count.box_a, "  after sa");
		reverse_rotate_a(box_a);
		//print_box(box_a, t_count.box_a, "  after rra");
	}
}
