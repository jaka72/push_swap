/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mychecker_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 17:50:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/21 17:21:03 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // for read()


#include "push_swap.h"

void	free_all(struct s_boxes *b)
{
	free(b->input);
	free(b->input_sorted_temp);
	free(b->input_simplified);
	free(b->finnal);
	free(b->box_a);
	free(b->box_b);
}

int	allocate_all_boxes(int argc, struct s_boxes *b)
{
	b->input_sorted_temp = malloc((argc - 1) * sizeof(int));
	b->input_simplified = malloc((argc - 1) * sizeof(int));
	b->finnal = malloc((argc - 1) * sizeof(int));
	b->box_a = malloc((argc - 1) * sizeof(int));
	b->box_b = malloc((argc - 1) * sizeof(int));
	if (!b->input_sorted_temp || !b->input_simplified)
		return (-1);
	if (!b->finnal || !b->box_a|| !b->box_b)
		return (-1);
	return (0);
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


void	print_arr(char	*operation)
{
	int	i;

	i = 0;
	printf("INSTR:");
	while (i < 4)
	{
		printf("[%c]", operation[i]);
		i++;
	}
	printf("\n");
}


void	choose_operation(char *opr, struct s_boxes *b)
{
	if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'a')
	{
		printf(" --- do rotate reverse box A\n");
		//print_box(b->input, 5, "before rra");
		reverse_rotate_a(b->input);
		//print_box(b->input, 5, "after rra");

	}
	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'b')
	{
		printf(" --- do rotate reverse box B\n");
		//rotate_reverse_b();
	}
	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'r')
	{
		printf(" --- do 2x rotate reverse box A and B\n");
		//rotate_reverse_a();
		//rotate_reverse_b();
	}
	else if (opr[0] == 'r' && opr[1] == 'a' && opr[2] == '\n')
	{
		printf(" --- do rotate box A\n");
		//print_box(b->input, 5, "before ra");
		rotate_a(b->input);
		//print_box(b->input, 5, "after ra");
	}
	else if (opr[0] == 'r' && opr[1] == 'b' && opr[2] == '\n')
	{
		printf(" --- do rotate box B\n");
		//rotate_b(b->box_b);
	}
	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == '\n')
	{
		printf(" --- do 2x rotate box A and B\n");
		//rotate_a(b->input);
		//rotate_b(b->box_b);
	}
	else if (opr[0] == 's' && opr[1] == 'a' && opr[2] == '\n')
	{
		printf(" --- do swap box A\n");
		swap_a(b->input);
	}
	else if (opr[0] == 's' && opr[1] == 'b' && opr[2] == '\n')
	{
		printf(" --- do swap box B\n");
		swap_b(b->box_b);
	}
	else if (opr[0] == 's' && opr[1] == 's' && opr[2] == '\n')
	{
		printf(" --- do 2x swap box A and B\n");
		//swap_a(b->input);
		//swap_b(b->box_b);
	}
	else if (opr[0] == 'p' && opr[1] == 'a' && opr[2] == '\n')
	{
		printf(" --- do push box A\n");
		push_a(b->box_b[0], b->input, b->box_b);
	}
	else if (opr[0] == 'p' && opr[1] == 'b' && opr[2] == '\n')
	{
		printf(" --- do push box B\n");
		push_b(b->input[0], b->input, b->box_b);
	}
}

int main(int argc, char **argv)
{
	t_box	b;
	int		br;
	char	c;
	char	c_end;
	char		operation[4];
	int		i;

	if (initial_check(argc, argv, &b) == -1)
		return (-1);

	printf(YEL"\nXXXXXXXX count input: %d\n"RES, t_count.box_a);


	b.box_b = calloc(argc - 1, sizeof(int));
	if (b.box_b == NULL)
		return (-1);

	i = 0;
	while (1)
	{
		br = read(0, &c, 1);
		if (br < 0)
		{
			printf("br is < 0\n");
			return (-1);
		}
		else
		{
			if (c == '\n' && c_end == '\n')
				//return (0);
				break ;
			//printf("%c", c);
			operation[i] = c;
			if (c == '\n')
			{
				//print_arr(operation);
				choose_operation(operation, &b);
				reset_arr(operation);
				i = -1;
			}
			i++;
			c_end = c;
		}
	}

	print_box(b.input, t_count.box_a, "box: input");
	printf("\ncount input: %d\n", t_count.box_a);

	// if (allocate_all_boxes(argc, &b) == -1)
	// 	return (-1);
	// if (argc - 1 == 2 || argc - 1 == 3)
	// 	return (sort_3_elements(argc, b.input, b.box_b));
	// else if (argc - 1 == 4 || argc - 1 == 5)
	// 	return (sort_5_elements(argc, b.input, b.box_b));
	// else
	// 	sort_5plus_elements(argc, &b);
	// t_oper.all = t_oper.pa + t_oper.pb + t_oper.ra + t_oper.sa + t_oper.rra;
	// free_all(&b);
	return (0);
}
