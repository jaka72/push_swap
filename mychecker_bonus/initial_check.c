/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initial_check.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 12:53:26 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/07 13:32:13 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

int	check_if_all_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if ((argv[i][j] == '-' || argv[i][j] == '+')
					&& !ft_isdigit(argv[i][j + 1]))
					return (error(-1, "Error\n"));
				else if (argv[i][j] != '-' && argv[i][j] != '+')
					return (error(-1, "Error\n"));
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_first_arg(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (-1);
		if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
			return (-1);
		i++;
	}
	return (0);
}

int	initial_check(int argc, char **argv, struct s_boxes *box)
{
	if (argc - 1 == 0)
		return (-1);
	if (check_if_all_numeric(argc, argv) < 0)
		return (-1);
	box->input = malloc((argc - 1) * sizeof(int));
	if (box->input == NULL)
		return (-1);
	if (copy_args_convert_to_ints(argc, argv, box->input) < 0)
		return (-1);
	if (check_identical_elements(argc, box->input) < 0)
	{
		free(box->input);
		return (-1);
	}
	reset_all(argc);
	return (0);
}
