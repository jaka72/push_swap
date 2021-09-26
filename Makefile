# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jmurovec <jmurovec@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/20 16:31:02 by jmurovec      #+#    #+#                  #
#    Updated: 2021/09/26 18:33:05 by jmurovec      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GRN = \033[1;32m
YEL = \033[0;33m
RED = \033[1;31m
WHITE = \033[0m

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
CC = gcc

LIBFT			= libft/libft.a
LIBFTDIR		= libft
OBJ_DIR 		= obj_dir

BONNUS 			= 0

# name of the operating system
UNAME_S := $(shell uname -s)
					
C_FILES_MAIN	= 	push_swap.c \
					utils.c \
					initial_check.c \
					initial_check_utils.c \
					operations_push.c \
					operations_swap.c \
					operations_rotate.c \
					sort_3_elements.c \
					sort_5_elements.c \
					sort_5plus_elements.c \
					sort_and_simplify.c
					

OBJ_FILES_MAIN 		= $(patsubst %, $(OBJ_DIR)/%, $(C_FILES_MAIN:.c=.o))

ifeq ($(BONNUS),0)
	MAKE_BONUS = 
	OBJ_FILES = $(OBJ_FILES_MAIN)
else
	MAKE_BONUS = bonus
	OBJ_FILES = $(OBJ_FILES_MAIN)
endif

all:	makedir $(NAME) $(MAKE_BONUS)
		@echo "$(GRN)\n--- MAKEFILE DONE ------------ \n$(WHITE)"
		
makedir:
		@echo "$(GRN)\n --- START MAKEFILE ------------ \n$(WHITE)"
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

bonus:	all
		@echo "$(YEL)\n- Go to Make Bonus: [$(BONNUS)] (System: $(UNAME_S)) --- $(WHITE)"
		BONNUS=1
		make -C ./mychecker_bonus

re:		fclean all

clean:
		rm -rf $(OBJ_DIR)
		
fclean:	clean
		cd ./libft && make fclean
		rm -f push_swap
		cd ./mychecker_bonus && make fclean

.PHONY: fclean bonus clean re all
