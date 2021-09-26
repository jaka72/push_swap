/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_swap.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 17:53:00 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/26 14:31:17 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

int	swap_b(int *box)
{
	int	temp;

	temp = box[0];
	box[0] = box[1];
	box[1] = temp;
	t_oper.sb++;
	return (0);
}

int	swap_a(int *box)
{
	int	temp;

	temp = box[0];
	box[0] = box[1];
	box[1] = temp;
	t_oper.sa++;
	return (0);
}
