/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mychecker_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 17:50:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/30 16:24:19 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

int	choose_operation_2(char *opr, struct s_boxes *b)
{
	if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'a')
		reverse_rotate_a(b->input);
	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'b')
		reverse_rotate_b(b->box_b);
	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'r')
	{
		reverse_rotate_a(b->input);
		reverse_rotate_b(b->box_b);
	}
	else if (opr[0] == 'p' && opr[1] == 'a' && opr[2] == '\0')
		push_a(b->box_b[0], b->input, b->box_b);
	else if (opr[0] == 'p' && opr[1] == 'b' && opr[2] == '\0')
		push_b(b->input[0], b->input, b->box_b);
	else
		return (-1);
	return (0);
}

int	choose_operation(char *opr, struct s_boxes *b)
{
	if (opr[0] == 's' && opr[1] == 'a' && opr[2] == '\0')
		swap_a(b->input);
	else if (opr[0] == 's' && opr[1] == 'b' && (opr[2] == ' '
			|| opr[2] == '\0'))
		swap_b(b->box_b);
	else if (opr[0] == 's' && opr[1] == 's' && (opr[2] == ' '
			|| opr[2] == '\0'))
		swap_a_swap_b(b);
	else if (opr[0] == 'r' && opr[1] == 'a' && (opr[2] == ' '
			|| opr[2] == '\0'))
		rotate_a(b->input);
	else if (opr[0] == 'r' && opr[1] == 'b' && (opr[2] == ' '
			|| opr[2] == '\0'))
		rotate_b(b->box_b);
	else if (opr[0] == 'r' && opr[1] == 'r' && (opr[2] == ' '
			|| opr[2] == '\0'))
	{
		rotate_a(b->input);
		rotate_b(b->box_b);
	}
	else if (choose_operation_2(opr, b) == -1)
		return (-1);
	return (0);
}

int	get_chars(char *operation, char *str, int *i)
{
	reset_arr(operation);
	*i = 0;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] != 's' && str[*i] != 'r' && str[*i] != 'p')
	{
		free(str);
		return (-1);
	}
	else
	{
		operation[0] = str[*i];
		(*i)++;
	}
	if (str[*i] != '\0' && str[*i] != ' ')
	{
		operation[1] = str[*i];
		(*i)++;
	}
	if (str[*i] != '\0' && str[*i] != ' ')
	{
		operation[2] = str[*i];
		(*i)++;
	}
	return (0);
}

int	read_and_choose(char *operation, struct s_boxes *b)
{
	int		i;
	char	*str;

	while (get_next_line(&str) > 0)
	{
		reset_arr(operation);
		if (get_chars(operation, str, &i) == -1)
			return (error(-1, "Error\n"));
		while (str[i])
		{
			if (str[i] != ' ' && str[i] != '\0')
			{
				free(str);
				return (error(-1, "Error\n"));
			}
			i++;
		}
		if (choose_operation(operation, b) == -1)
		{
			free(str);
			return (error(-1, "Error\n"));
		}
		free(str);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_box	b;
	char	operation[4];

	if (initial_check(argc, argv, &b) == -1)
		return (-1);
	b.box_b = calloc(argc - 1, sizeof(int));
	if (b.box_b == NULL)
		return (-1);
	if (read_and_choose(operation, &b) == -1)
		return (-1);
	final_check(&b);
	free_both(&b);
	return (0);
}
