NAME =			checker
HEADER =		$(NAME).h
CC =			cc
CFLAGS =		-Wall -Wextra -Werror
SRCS =			main.c error/error_utils.c error/error.c main_utils/main_utils.c main_utils/free_utils.c \
				operations/change_operations.c operations/print_operations_utils.c \
				operations/print_operations.c operations/push_rotate.c operations/swap.c \
				error/error_operations.c main_utils/checker_utils.c main_utils/utils_checker.c

LIBFT =			../libft/
LIBFT_PATH =	$(LIBFT)libft.a
OBJ	=			$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -g $< -o $@

all:	libft_make $(NAME) 

$(NAME):	$(HEADER) $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_PATH) -o $(NAME)

libft_make:
	make -C $(LIBFT)

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
.PHONY: all clean fclean re
