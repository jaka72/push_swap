/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_push.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/18 12:53:10 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/22 16:50:29 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_a(int *box_a)
{
	int	i;

	i = 0;
	while (i < t_count.box_a)
	{
		box_a[i] = box_a[i + 1];
		i++;
	}
}

void	refresh_b(int *box_b)
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
	int	i;

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
	int	i;

	printf(MAG"enter push_b, cout a: %d\n"RES, t_count.box_a);
	if (t_count.box_a < 1)
		return ;
	printf(MAG"     after count < 1\n"RES);
	
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
