/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_5_elements.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 13:16:41 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/19 15:42:24 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_5_elements(int argc, int *box_a, int *box_b)
{
    int	i;
	int	min_0;
	int	min_1;
    int nr_min;

    // move 2 minimum numbers to box_b
    get_min(box_a, &min_0);
    while (box_a[0] != min_0)
        reverse_rotate_a(box_a);
    push_b(box_a[0], box_a, box_b);
    nr_min = 1;

	//print_box(box_a, t_count.box_a, "A 1");
	//print_box(box_b, t_count.box_b, "B 1");


    if (argc - 1 == 5)
    {
        ////printf(RED"5 elements present\n"RES);
        get_min(box_a, &min_1);
        while (box_a[0] != min_1)
            rotate_a(box_a);
        push_b(box_a[0], box_a, box_b);
        nr_min = 2;
    }
    //print_box(box_a, t_count.box_a, "A 2");
	//print_box(box_b, t_count.box_b, "B 2");
    
    sort_3_elements(argc, box_a, box_b);
    //print_box(box_a, t_count.box_a, "After sort 3 elements \nA 2");
	//print_box(box_b, t_count.box_b, "B 2");
    // check the 2 elements in box_b // probably not necessary, its alway right order
    //if (box_b[0] > box_b[1])
    //   swap_b(box_b);
    i = 0;
    while (i < nr_min)
    {
        push_a(box_b[0], box_a, box_b);
        i++;
    }
}
