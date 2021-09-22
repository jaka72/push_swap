#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

 #include <stdio.h>
 #include <stdlib.h>
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


struct	s_boxes
{
	int *input;
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
	int	pa;
	int	pb;
	int	ra;
	int	rra;
	int	sa;
	int	sb;
	int	all;
}	t_oper;

void    get_min(int *box_a, int *min);
void    get_max(int argc, int *box_a, int *min);

int     check_if_sorted(int argc, int *input);
int		check_identical_elements(int argc, int *input);

void    sort_3_elements(int argc, int *box_a, int *box_b);
void    sort_5_elements(int argc, int *box_a, int *box_b);

void	copy_args_convert_to_ints(int argc, char *argv[], int *input);
void    copy_to_sorted_temp(int argc, int *input, int *input_sorted_temp);
void    bubble_sort(int argc, int *input_sorted_temp);
void    store_to_simplyfied(int argc, int *input, int *input_sorted_temp, int *input_simplified);
void    find_longest_nr(int argc, int *input_simplified);
void	find_nr_bits(void);

void	push_a(int x, int *box_a, int *box_b);
void	push_b(int x, int *box_a, int *box_b);
void	rotate_a(int *box_a);
void	reverse_rotate_a(int *box_a);
void	swap_a(int *box);
void	swap_b(int *box);

void	print_box(int *box, int nr, char *s);

#endif