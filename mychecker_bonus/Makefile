# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jmurovec <jmurovec@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/20 16:31:02 by jmurovec      #+#    #+#                  #
#    Updated: 2021/09/26 14:05:30 by jaka          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GRN = \033[1;32m
YEL = \033[0;33m
RED = \033[1;31m
WHITE = \033[0m

# gcc push_swap.c sort_3_elements.c sort_5_elements.c sort_and_simplify.c utils.c pa_ra_sa_rra.c libft.a && ./a.out 99 66  44 55  33 22 11 678

NAME = mychecker_bonus
FLAGS = -Wall -Wextra -Werror
CC = gcc

NORM = norminette *.c *.h

#DEPS = cub3d_header.h libft.h

LIBFT			= libft/libft.a
LIBFTDIR		= libft
OBJ_DIR 		= obj_dir

BONNUS 		= 0

# name of the operating system
UNAME_S := $(shell uname -s)
					
C_FILES_MAIN	= 	mychecker_bonus.c \
					mychecker_bonus_utils.c \
					initial_check.c \
					initial_check_utils.c \
					operations_push.c \
					operations_swap.c \
					operations_rotate.c \
					sort_3_elements.c \
					sort_5_elements.c \
					sort_5plus_elements.c \
					sort_and_simplify.c \
					final_check.c \
					z_print_box.c

C_FILES_BONUS	=	

#OBJ_FILES 			= $(C_FILES:.c=.o)
#OBJ_FILES			= $(addsuffix .o, $(addpreffix $(OBJ_DIR), $(C_FILES)))
OBJ_FILES_MAIN 		= $(patsubst %, $(OBJ_DIR)/%, $(C_FILES_MAIN:.c=.o))
OBJ_FILES_BONUS		= $(patsubst %, $(OBJ_DIR)/%, $(C_FILES_BONUS:.c=.o))


ifeq ($(BONNUS),0)
	OBJ_FILES = $(OBJ_FILES_MAIN)
else
	OBJ_FILES = $(OBJ_FILES_MAIN) $(OBJ_FILES_BONUS)
endif

#reset_bonus:
#		@echo "$(GRN)\n--- RESET BONUS TO 0  ------------ \n$(WHITE)"
#		$(MAKE) BONNUS=0    # this causes eternal loop

all:	makedir $(NAME)
		@echo "$(GRN)\n--- MAKEFILE DONE ------------ \n$(WHITE)"
		
makedir:
		@echo "$(GRN)\n --- START MAKEFILE ------------ \n$(WHITE)"
#		rm -f cub3D
#		@echo "$(RED) BONNUUS IS $(BONNUS) $(WHITE)"
		@echo "$(GRN) Making obj_dir Directory $(WHITE)"
		mkdir -p $(OBJ_DIR)/
		@echo "$(GRN)\n Making libft.a Library $(WHITE)"
		make -C ./libft
		@echo "$(GRN)\n Start making object files $(WHITE)"



$(OBJ_DIR)/%.o: 	%.c
		@echo "$(YEL) --- making %.o file --- $(WHITE)"
		gcc -g $(FLAGS) -c $< -o $@


$(NAME): $(OBJ_FILES)
		@echo "$(GRN)\n - Making cub3D Executable --- $(WHITE)"
		gcc $^ $(FLAGS) $(LIBFT) -o $(NAME)

bonus:
#		@echo "$(GRN)\n- Start Makefile Cub3D with Bonus: [$(BONNUS)] (System: $(UNAME_S)) --- $(WHITE)"
#		@$(MAKE) $(MAKEDIR) BONNUS=1


re:		fclean all

mlxclean:
		@cd mlx && make clean
		@cd mlx && rm -f *.swiftsourceinfo

norm:	
		@echo "\tlibft\n" && cd libft/libft && $(NORM)
#		@echo "\tget_next_line\n" && cd get_next_line && $(NORM)
#		@echo "\tcub3D\n" && $(NORM)

clean:	#mlxclean
		rm -rf $(OBJ_DIR)
#		cd libft && make fclean
		

fclean:	clean
#		rm -f $(OBJ_FILES)
#		rm -f *.d
		cd libft && make fclean
		rm -f push_swap
#		rm -f *.o
#		rm -f $(LIBFT)

.PHONY: mlx clean_mlx norm fclean bonus clean re all