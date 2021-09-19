/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pa_ra_sa_rra.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/18 12:53:10 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/19 20:23:59 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    refresh_a(int *box_a)
{
	int	i;

	i = 0;
	while (i < t_count.box_a)
	{
		box_a[i] = box_a[i + 1];
		i++;
	}
}

void    refresh_b(int *box_b)
{
	int	i;

	i = 0;
	while (i < t_count.box_b)
	{
		box_b[i] = box_b[i + 1];
		i++;
	}
}

void	push_a(int b, int *box_a, int *box_b)
{
	int i;

	if (t_count.box_b == 0)
		return ;

	i = t_count.box_a;
	while (i > 0)
	{
		// first move every element in a one place up, to make space 
		//  in the beginning
		box_a[i] = box_a[i - 1];
		i--;
	}
	box_a[0] = b; // as last, copy a[j] to first place in b[0]
	t_count.box_a++;
	t_count.box_b--;
	t_oper.pa++;
	//printf(MAG"pa%d \n"RES, t_oper.pa);
	printf("pa\n");
	refresh_b(box_b);
}


void	push_b(int a, int *box_a, int *box_b)
{
	int i;

	if (t_count.box_a < 1)
		return ;

	i = t_count.box_b;
	while (i > 0)
	{
		// first move every element in b one place up, to make space 
		//  in the beginning
		box_b[i] = box_b[i - 1];
		i--;
	}
	box_b[0] = a; // as last, copy a[j] to first place in b[0]
	t_count.box_a--;
	t_count.box_b++;
	t_oper.pb++;
	//printf(MAG"pb%d \n"RES, t_oper.pb);
	printf("pb\n");
	refresh_a(box_a);
}


