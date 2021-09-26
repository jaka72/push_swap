/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   z_print_box.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 18:02:20 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/26 14:31:49 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

void	print_box(int *box, int nr, char *s)
{
	int i;
	
	i = 0;
	while (i < nr)
	{
		printf(RED"%d "RES, box[i]);
		i++;
	}
	printf("%s (nr elem: %d) ", s, nr);
}
