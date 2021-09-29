/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mychecker_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 17:50:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/29 15:08:56 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker_bonus.h"

void	choose_operation_2(char *opr, struct s_boxes *b)
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
	else if (opr[0] == 'p' && opr[1] == 'a' && opr[2] == '\n')
		push_a(b->box_b[0], b->input, b->box_b);
	else if (opr[0] == 'p' && opr[1] == 'b' && opr[2] == '\n')
		push_b(b->input[0], b->input, b->box_b);
}

void	choose_operation(char *opr, struct s_boxes *b)
{
	if (opr[0] == 's' && opr[1] == 'a' && opr[2] == '\n')
		swap_a(b->input);
	else if (opr[0] == 's' && opr[1] == 'b' && opr[2] == '\n')
		swap_b(b->box_b);
	else if (opr[0] == 's' && opr[1] == 's' && opr[2] == '\n')
	{
		swap_a(b->input);
		swap_b(b->box_b);
	}
	else if (opr[0] == 'r' && opr[1] == 'a' && opr[2] == '\n')
		rotate_a(b->input);
	else if (opr[0] == 'r' && opr[1] == 'b' && opr[2] == '\n')
		rotate_b(b->box_b);
	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == '\n')
	{
		rotate_a(b->input);
		rotate_b(b->box_b);
	}
	else
		choose_operation_2(opr, b);
}

int	read_chars(char *c, struct s_boxes *b)
{
	int	br;

	br = read(0, c, 1);
	if (br < 0)
	{
		free_both(b);
		return (-1);
	}

	///// 
	if (*c != 's' && *c != 'a' && *c != 'r' && *c != '\n')
	{
		free_both(b);
		ft_putstr("Error\n");
		return (-1);
	}


	return (0);
}

int	read_and_choose(struct s_boxes *b, char *operation)
{
	int		i;
	char	c;
	char	c_end;

	i = 0;
	while (1)
	{
		if (read_chars(&c, b) == -1)
			return (-1);
		else
		{
			if (c == '\n' && c_end == '\n')
				break ;
			operation[i] = c;
			if (c == '\n')
			{
				choose_operation(operation, b);
				reset_arr(operation);
				i = -1;
			}
			i++;
			c_end = c;
		}
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
	if (read_and_choose(&b, operation) == -1)
		return (-1);
	final_check(&b);
	free_both(&b);
	return (0);
}
