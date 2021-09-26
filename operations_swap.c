/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_swap.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 17:53:00 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/25 19:46:47 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_b(int *box, struct s_boxes *b)
{
	int	temp;

	temp = box[0];
	box[0] = box[1];
	box[1] = temp;
	b->count.sb++;
	ft_putstr("sb\n");
	return (0);
}

int	swap_a(int *box, struct s_boxes *b)
{
	int	temp;

	temp = box[0];
	box[0] = box[1];
	box[1] = temp;
	b->count.sa++;
	ft_putstr("sa\n");
	return (0);
}
