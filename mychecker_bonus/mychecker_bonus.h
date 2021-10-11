/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mychecker_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 09:30:50 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/08 09:30:51 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYCHECKER_BONUS_H
# define MYCHECKER_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

struct	s_data
{
	int	max_nr_bits;
	int	longest_nr;
}	t_data;

struct	s_count
{
	int	box_a;
	int	box_b;
}	t_count;

typedef struct s_boxes
{
	int	*input;
	int	*input_sorted_temp;
	int	*input_simplified;
	int	*finnal;
	int	*box_a;
	int	*box_b;
}	t_box;

struct	s_operations
{
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	pa;
	int	pb;
	int	all;
}	t_oper;

int		initial_check(int argc, char **argv, struct s_boxes *box);
int		check_identical_elements(int argc, int *input);
int		check_if_sorted(int argc, int *input);
int		copy_args_convert_to_ints(int argc, char *argv[], int *input);

int		swap_a(int *box);
int		swap_b(int *box);
void	swap_a_swap_b(struct s_boxes *b);
void	rotate_a(int *box_a);
void	rotate_b(int *box_b);
void	reverse_rotate_a(int *box_a);
void	reverse_rotate_b(int *box_a);
void	push_a(int x, int *box_a, int *box_b);
void	push_b(int x, int *box_a, int *box_b);

int		check_if_a_sorted(int *input);
int		final_check(struct s_boxes *b);

void	free_both(struct s_boxes *b);
void	reset_arr(char	*operation);

void	reset_all(int argc);
int		error(int r, char *msg);

# define BLKB "\e[40m"
# define HYEL "\e[0;93m"
# define HGRN "\e[0;92m"
# define HWHT "\e[0;97m"
# define YEL "\e[0;33m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"
# define RES "\x1B[0m"

#endif
