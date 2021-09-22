/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   z_print_box.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 18:02:20 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/20 18:02:40 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_box(int *box, int nr, char *s)
{
	int i;
	printf("\n%s (nr elem: %d)\n", s, nr);
	i = 0;
	while (i < nr)
	{
		printf("  %d["RED"%d"RES"],", i, box[i]);
		i++;
	}
	//printf("\n");
}
