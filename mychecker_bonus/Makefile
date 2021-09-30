# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jmurovec <jmurovec@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/20 16:31:02 by jmurovec      #+#    #+#                  #
#    Updated: 2021/09/30 10:38:01 by jaka          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GRN = \033[1;32m
YEL = \033[0;33m
RED = \033[1;31m
MAG = \033[1;36m
WHITE = \033[0m

NAME = checker_bonus
FLAGS = -Wall -Wextra -Werror
CC = gcc

LIBFT			= libft/libft.a
LIBFTDIR		= libft
OBJ_DIR 		= obj_dir


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
					get_next_line/get_next_line.c


OBJ_FILES_MAIN 		= $(patsubst %, $(OBJ_DIR)/%, $(C_FILES_MAIN:.c=.o))

#ifeq ($(BONNUS),0)
	OBJ_FILES = $(OBJ_FILES_MAIN)
#else
#	OBJ_FILES = $(OBJ_FILES_MAIN) $(OBJ_FILES_BONUS)
#endif

all:	makedir $(NAME)
		@echo "$(MAG)\n--- MAKEFILE DONE ------------ \n$(WHITE)"
		
makedir:
		@echo "$(MAG)\n --- START MAKEFILE ------------ \n$(WHITE)"
		@echo "$(MAG) Making obj_dir Directory $(WHITE)"
		mkdir -p $(OBJ_DIR)/  $(OBJ_DIR)/get_next_line
		@echo "$(MAG)\n Making libft.a Library $(WHITE)"
		make -C ./libft
		@echo "$(MAG)\n Start making object files $(WHITE)"



$(OBJ_DIR)/%.o: 	%.c
		@echo "$(MAG) --- making %.o file --- $(WHITE)"
		gcc -g $(FLAGS) -c $< -o $@


$(NAME): $(OBJ_FILES)
		@echo "$(MAG)\n - Making Mychecker_bonus Executable --- $(WHITE)"
		gcc $^ $(FLAGS) $(LIBFT) -o $(NAME)
		cp checker_bonus ../

re:		fclean all

norm:	
		@echo "\tlibft\n" && cd libft/libft && $(NORM)

clean:	
		rm -rf $(OBJ_DIR)
		rm checker_bonus
		

fclean:	clean
		cd libft && make fclean
		rm -f ../checker_bonus

.PHONY: fclean bonus clean re all