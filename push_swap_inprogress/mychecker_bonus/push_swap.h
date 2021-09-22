#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "./libft/libft.h"

 #define BLKB "\e[40m"
 #define HYEL "\e[0;93m"
 #define HGRN "\e[0;92m"
 #define HWHT "\e[0;97m"
 #define YEL   "\e[0;33m"
 #define RED   "\x1B[31m"
 #define GRN   "\x1B[32m"
 #define BLU   "\x1B[34m"
 #define MAG   "\x1B[35m"
 #define CYN   "\x1B[36m"
 #define WHT   "\x1B[37m"
 #define RES   "\x1B[0m"


typedef struct	s_boxes
{
	int *input;
	int *input_sorted_temp;
	int	*input_simplified;
	int	*finnal;
	int	*box_a;
	int	*box_b;
}	t_box;

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

void    get_min(int *box_a, int *min);
void    get_max(int argc, int *box_a, int *min);

int	initial_check(int argc, char **argv, struct s_boxes *box);
//int	check_if_sorted(int argc, int *input);
//int		check_identical_elements(int argc, int *input);

int	sort_3_elements(int argc, int *box_a, int *box_b);
int	sort_5_elements(int argc, int *box_a, int *box_b);
int	sort_5plus_elements(int argc, struct s_boxes *b);

void	copy_args_convert_to_ints(int argc, char *argv[], int *input);
void    copy_to_sorted_temp(int argc, int *input, int *input_sorted_temp);
void    bubble_sort(int argc, int *input_sorted_temp);
void    store_to_simplyfied(int argc, int *input, int *input_sorted_temp, int *input_simplified);
void    find_longest_nr(int argc, int *input_simplified);
void	find_nr_bits(void);

int		swap_a(int *box);
int		swap_b(int *box);
void	rotate_a(int *box_a);
void	rotate_b(int *box_b);
void	reverse_rotate_a(int *box_a);
void	reverse_rotate_b(int *box_a);
void	push_a(int x, int *box_a, int *box_b);
void	push_b(int x, int *box_a, int *box_b);

void	print_box(int *box, int nr, char *s);

#endif
