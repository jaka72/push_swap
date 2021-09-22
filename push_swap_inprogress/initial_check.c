/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initial_check.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 12:53:26 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/22 18:32:28 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_all(int argc)
{
	t_count.box_a = argc - 1;
	t_count.box_b = 0;
	t_oper.pb = 0;
	t_oper.pa = 0;
	t_oper.ra = 0;
	t_oper.rra = 0;
	t_oper.sa = 0;
	t_oper.sb = 0;
}

int	check_identical_elements(int argc, int *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (input[i] == input[j])
			{
				//printf("Error\n There are 2 identical"
				//	" elements i%d[%d]  j%d[%d]\n",
				//	i, input[i], j, input[j]);
				ft_putstr("Error\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_sorted(int argc, int *input)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (input[i] < input[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_if_all_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	//while (i < argc - 1)
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			printf("j%d i%d: [%c] \n", j, i, argv[i][j]);
			if (!ft_isdigit(argv[i][j]))
			{
				// HERE CHECK, IF IT IS SINGLE - OR + , THEN RETURN, IF IT IS -3  OR +3, IT IS OK
				printf("Error\n Argument isn't numeric. [%c] \n", argv[i][j]);
				ft_putstr("Error\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	initial_check(int argc, char **argv, struct s_boxes *box)
{
	if (argc - 1 <= 1)
		return (-1);
	if (check_if_all_numeric(argc, argv) < 0)
		return (-1);
	box->input = malloc((argc - 1) * sizeof(int));
	if (box->input == NULL)
		return (-1);
	copy_args_convert_to_ints(argc, argv, box->input);
	if (check_identical_elements(argc, box->input) < 0)
	{
		free(box->input);
		return (-1);
	}
	if (check_if_sorted(argc, box->input) == 1)
	{
		//printf("Error\n Numbers are already sorted.\n");
		free(box->input);
		return (-1);
	}
	reset_all(argc);
	return (0);
}
