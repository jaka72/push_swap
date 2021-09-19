NAME 			=	libft.a

C_FILES 		=	ft_isdigit.c \
					ft_atoi.c


CFLAGS 			= 	-Wall -Wextra -Werror 	#-fsanitize=address -g

HEADER_FILES 	=	#./inc/new_header.h # libft.h

#CC = clang  # IS THIS NECESSARY ??

O_FILES 		= 	$(C_FILES:.c=.o)


%.o:		%.c  #$(HEADER_FILES)
				@echo " --- Compiling $@"
				$(CC) -c $(CFLAGS) -o $@ $<


$(NAME):	$(O_FILES)
				@echo "Compiling NAME"
				$(AR) -r $@ $^



all: 	$(NAME)

clean:
			rm -f $(O_FILES)

fclean:	clean
			rm -f $(NAME)
#			rm a.out

re:		fclean all

.PHONY:	all clean fclean re