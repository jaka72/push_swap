/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_elements.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 12:29:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/19 16:47:36 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void get_max(int argc, int *box_a, int *max)
{
    int i;
    
    i = 1;
	*max = box_a[0];
	while (i < argc - 1)
	{
		if (*max < box_a[i])
			*max = box_a[i];
		i++;
	}
	//printf("\nFound largest number:  %d\n", *max);
}

void get_min(int *box_a, int *min)
{
    int i;

	////printf("\nFind min in box a, count: %d\n", t_count.box_a);
    i = 1;
	*min = box_a[0];
	while (i < t_count.box_a)
	{
		if (*min > box_a[i])
			*min = box_a[i];
		i++;
	}
	//printf("\nFound smallest number: %d", *min);
}


void	swap_b(int *box)
{
	int	temp;

	temp = box[0];
	box[0] = box[1];
	box[1] = temp;
	t_oper.sb++;
	//printf(MAG"sb%d \n"RES, t_oper.sb);
	printf(YEL"sa\n"RES);
}


void	swap_a(int *box)
{
	int	temp;

	temp = box[0];
	box[0] = box[1];
	box[1] = temp;
	t_oper.sa++;
	//printf(MAG"sa%d \n"RES, t_oper.sa);
	printf("sa\n");
}



void    sort_3_elements(int argc, int *box_a, int *box_b)
{
	//int	i;
	int	max;
	int	min;

	//print_box(box_a, t_count.box_a, "At start of sort 3");

	// in case just 2 elements
	if (argc - 1 == 2)
	{
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
