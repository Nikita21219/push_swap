NAME =			push_swap
HEADER =		push_swap.h
CC =			cc
CFLAGS =		-Wall -Wextra -Werror
SRCS =			main.c error/error.c operations/push_rotate.c main_sort/main_sort.c \
				main_sort/mid.c main_utils/main_utils.c operations/print_operations.c operations/print_operations_utils.c \
				error/error_utils.c main_utils/free_utils.c \
				operations/swap.c operations/change_operations.c \
				main_sort/move_elements.c main_sort/init_scores.c \
				main_sort/get_score_a.c main_sort/main_sort_utils.c \
				main_utils/del_helper.c

LIBFT =			libft/
LIBFT_PATH =	libft/libft.a
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
