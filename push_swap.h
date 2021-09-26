#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_data
{
	int	max_nr_bits;
	int	longest_nr;
}	t_dta;

typedef struct s_count
{
	int	a;
	int	b;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	sa;
	int	sb;
	int	all;
}	t_cnt;

typedef struct s_boxes
{
	int		*input;
	int		*input_sorted_temp;
	int		*input_simplified;
	int		*finnal;
	int		*box_a;
	int		*box_b;
	t_dta	data;
	t_cnt	count;
}	t_box;

void	get_min(int *min, int *box_a, struct s_boxes *box);
void	get_max(int argc, int *max, int *box_a);

int		initial_check(int argc, char **argv, struct s_boxes *box);
int		check_identical_elements(int argc, int *input);
int		check_if_sorted(int argc, int *input);

int		sort_3_elements(int argc, int *box_a, struct s_boxes *box);
int		sort_5_elements(int argc, int *box_a, int *box_b, struct s_boxes *box);
int		sort_5plus_elements(int argc, struct s_boxes *b);

int		copy_args_convert_to_ints(int argc, char *argv[], int *input);
void	copy_to_sorted_temp(int argc, int *input, int *input_sorted_temp);
void	bubble_sort(int argc, int *input_sorted_temp);
void	store_to_simplyfied(int argc, int *input, int *input_sorted_temp,
			int *input_simplified);
void	find_longest_nr(int argc, int *input_simplified, struct s_boxes *box);
void	find_nr_bits(struct s_boxes *box);

int		swap_a(int *box, struct s_boxes *b);
int		swap_b(int *box, struct s_boxes *b);
void	push_a(int x, int *box_a, int *box_b, struct s_boxes *box);
void	push_b(int x, int *box_a, int *box_b, struct s_boxes *box);
void	rotate_a(int *box_a, struct s_boxes *box);
void	rotate_b(int *box_b, struct s_boxes *box);
void	reverse_rotate_a(int *box_a, struct s_boxes *box);
void	reverse_rotate_b(int *box_b, struct s_boxes *box);

int		error(int r, char *msg);
void	reset_all(int argc, struct s_boxes *box);
void	free_all(struct s_boxes *b);

void	print_box(int *box, int nr, char *s);

# define BLKB "\e[40m"
# define HYEL "\e[0;93m"
# define HGRN "\e[0;92m"
# define HWHT "\e[0;97m"
# define YEL   "\e[0;33m"
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RES   "\x1B[0m"

#endif
