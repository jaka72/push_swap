# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jmurovec <jmurovec@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/20 16:31:02 by jmurovec      #+#    #+#                  #
#    Updated: 2021/09/26 18:55:37 by jmurovec      ########   odam.nl          #
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

NORM = norminette *.c *.h

LIBFT			= libft/libft.a
LIBFTDIR		= libft
OBJ_DIR 		= obj_dir

BONNUS 			= 0
					
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
					final_check.c

C_FILES_BONUS	=	

OBJ_FILES_MAIN 		= $(patsubst %, $(OBJ_DIR)/%, $(C_FILES_MAIN:.c=.o))

ifeq ($(BONNUS),0)
	OBJ_FILES = $(OBJ_FILES_MAIN)
else
	OBJ_FILES = $(OBJ_FILES_MAIN) $(OBJ_FILES_BONUS)
endif

all:	makedir $(NAME)
		@echo "$(MAG)\n--- MAKEFILE DONE ------------ \n$(WHITE)"
		
makedir:
		@echo "$(MAG)\n --- START MAKEFILE ------------ \n$(WHITE)"
		@echo "$(MAG) Making obj_dir Directory $(WHITE)"
		mkdir -p $(OBJ_DIR)/
		@echo "$(MAG)\n Making libft.a Library $(WHITE)"
		make -C ./libft
		@echo "$(MAG)\n Start making object files $(WHITE)"



$(OBJ_DIR)/%.o: 	%.c
		@echo "$(MAG) --- making %.o file --- $(WHITE)"
		gcc -g $(FLAGS) -c $< -o $@


$(NAME): $(OBJ_FILES)
		@echo "$(MAG)\n - Making Mychecker_bonus Executable --- $(WHITE)"
		gcc $^ $(FLAGS) $(LIBFT) -o $(NAME)
		mv checker_bonus ../

re:		fclean all

norm:	
		@echo "\tlibft\n" && cd libft/libft && $(NORM)

clean:	
		rm -rf $(OBJ_DIR)
		

fclean:	clean
		cd libft && make fclean
		rm -f ../checker_bonus

.PHONY: fclean bonus clean re all