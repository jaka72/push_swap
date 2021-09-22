/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_swap.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 17:53:00 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/21 12:27:12 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_b(int *box)
{
	int	temp;

	temp = box[0];
	box[0] = box[1];
	box[1] = temp;
	t_oper.sb++;
	//printf(MAG"sb%d \n"RES, t_oper.sb);
	printf("sb\n");
	return (0);
}

int	swap_a(int *box)
{
	int	temp;

	temp = box[0];
	box[0] = box[1];
	box[1] = temp;
	t_oper.sa++;
	//printf(MAG"sa%d \n"RES, t_oper.sa);
	printf("sa\n");
	return (0);
}
