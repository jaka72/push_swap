/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_rotate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 17:52:29 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/22 15:36:12 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// last becomes first
void	reverse_rotate_b(int *box_b)
{
	int	i;
	int	temp;

	i = t_count.box_b;
	temp = box_b[t_count.box_b - 1];
	//printf(GRN"\ntemp: %d, last place: %d \n"RES, temp, t_count.box_a - 1);
	while (i > 0)
	{
		box_b[i] = box_b[i - 1];
		i--;
	}
	box_b[0] = temp;
	t_oper.rrb++;
	//printf(MAG"rra%d \n"RES, t_oper.rra);
	printf("rrb\n");
}



// last becomes first
void	reverse_rotate_a(int *box_a)
{
	int	i;
	int	temp;

	i = t_count.box_a;
	temp = box_a[t_count.box_a - 1];
	//printf(GRN"\ntemp: %d, last place: %d \n"RES, temp, t_count.box_a - 1);
	while (i > 0)
	{
		box_a[i] = box_a[i - 1];
		i--;
	}
	box_a[0] = temp;
	t_oper.rra++;
	//printf(MAG"rra%d \n"RES, t_oper.rra);
	printf("rra\n");
}

// ?????
//==894228== Invalid read of size 4
//==894228==    at 0x1097D4: rotate_a 


void	rotate_b(int *box_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = box_b[0];
	while (i < t_count.box_b)
	{
		box_b[i] = box_b[i + 1];
		i++;
	}
	box_b[t_count.box_b - 1] = temp;
	t_oper.rb++;
	//printf(MAG"ra%d \n"RES, t_oper.ra);
	printf("rb\n");
}





void	rotate_a(int *box_a)
{
	int	i;
	int	temp;

	i = 0;
	temp = box_a[0];
	while (i < t_count.box_a)
	{
		box_a[i] = box_a[i + 1];
		i++;
	}
	box_a[t_count.box_a - 1] = temp;
	t_oper.ra++;
	//printf(MAG"ra%d \n"RES, t_oper.ra);
	printf("ra\n");
}
