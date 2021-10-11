/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_and_simplify.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:44:24 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/06 13:12:26 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

int	copy_args_convert_to_ints(int argc, char *argv[], int *input)
{
	int	i;
	int	temp;
	int	flag_overflow;

	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(argv[i], &flag_overflow);
		input[i - 1] = temp;
		i++;
		if (flag_overflow == 1)
		{
			ft_putstr("Error\n");
			return (-1);
		}
	}
	return (0);
}
