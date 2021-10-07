/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mychecker_bonus_utils.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 13:46:44 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/06 13:15:49 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

void	free_both(struct s_boxes *b)
{
	free(b->input);
	free(b->box_b);
}

void	reset_arr(char	*operation)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		operation[i] = 0;
		i++;
	}
}
