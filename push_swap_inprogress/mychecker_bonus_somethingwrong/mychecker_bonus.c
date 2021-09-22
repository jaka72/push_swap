/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mychecker_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 17:50:48 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/22 16:45:07 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // for read()

#include "push_swap.h"

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


void	swaps(char *opr, struct s_boxes *b)
{
	if (opr[0] == 's' && opr[1] == 'a' && opr[2] == '\n')
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
		swap_a(b->input);
		swap_b(b->box_b);
	}
}



void	choose_operation(char *opr, struct s_boxes *b)
{
	// if (opr[0] == 's')
	// 	swaps(opr, b);
	if (opr[0] == 's' && opr[1] == 'a' && opr[2] == '\n')
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
		swap_a(b->input);
		swap_b(b->box_b);
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
		rotate_b(b->box_b);
	}
	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == '\n')
	{
		printf(" --- do 2x rotate box A and B\n");
		rotate_a(b->input);
		rotate_b(b->box_b);
	}
	if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'a')
	{
		printf(" --- do rotate reverse box A\n");
		//print_box(b->input, 5, "before rra");
		reverse_rotate_a(b->input);
	}
	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'b')
	{
		printf(" --- do rotate reverse box B\n");
		reverse_rotate_b(b->box_b);
	}
	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'r')
	{
		printf(" --- do 2x rotate reverse box A and B\n");
		reverse_rotate_a(b->input);
		reverse_rotate_b(b->box_b);
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





// void	choose_operation_NOCOMMENTS(char *opr, struct s_boxes *b)
// {
// 	if (opr[0] == 's' && opr[1] == 'a' && opr[2] == '\n')
// 		swap_a(b->input);
// 	else if (opr[0] == 's' && opr[1] == 'b' && opr[2] == '\n')
// 		swap_b(b->box_b);
// 	else if (opr[0] == 's' && opr[1] == 's' && opr[2] == '\n')
// 	{
// 		swap_a(b->input);
// 		swap_b(b->box_b);
// 	}
// 	else if (opr[0] == 'r' && opr[1] == 'a' && opr[2] == '\n')
// 		rotate_a(b->input);
// 	else if (opr[0] == 'r' && opr[1] == 'b' && opr[2] == '\n')
// 		rotate_b(b->box_b);
// 	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == '\n')
// 	{
// 		rotate_a(b->input);
// 		rotate_b(b->box_b);
// 	}
// 	if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'a')
// 	{
// 		reverse_rotate_a(b->input);
// 		reverse_rotate_b(b->box_b);
// 	}
// 	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'b')
// 		reverse_rotate_b(b->box_b);
// 	else if (opr[0] == 'r' && opr[1] == 'r' && opr[2] == 'r')
// 	{
// 		reverse_rotate_a(b->input);
// 		reverse_rotate_b(b->box_b);
// 	}
// 	else if (opr[0] == 'p' && opr[1] == 'a' && opr[2] == '\n')
// 		push_a(b->box_b[0], b->input, b->box_b);
// 	else if (opr[0] == 'p' && opr[1] == 'b' && opr[2] == '\n')
// 		push_b(b->input[0], b->input, b->box_b);
// }

//int	check_if_b_empty

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


	

	//check_if_a_sorted(b.input);
	//check_if_b_empty(b.box_b);
	if (t_count.box_b != 0)
	{
		ft_putstr("KO\n  B is not empty\n");
		return (-1);
	}

	printf("\ncount input: %d\n", t_count.box_a);
	printf("\ncount box b: %d\n", t_count.box_b);
	print_box(b.input, t_count.box_a, "box: input");
	

	// Testing rotate b and reverse rotate b
	// t_count.box_b = 6;
	// print_box(b.input, t_count.box_b, "before rb");
	// rotate_b(b.input);
	// print_box(b.input, t_count.box_b, "after rb");
	// print_box(b.input, t_count.box_b, "before rrb");
	// reverse_rotate_b(b.input);
	// print_box(b.input, t_count.box_b, "after rrb");


	free(b.input);
	free(b.box_b);

	return (0);
}



