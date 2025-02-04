NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory/chunk.c  mandatory/extra_outils.c  mandatory/hardcode.c  mandatory/operations_a.c  mandatory/push_swap.c  mandatory/sorting_algo.c  mandatory/extra_operation.c  mandatory/handle_input.c  mandatory/linked_list_outils.c  mandatory/operations_b.c  mandatory/set_indice_of_each_node.c
BSRCS = bonus/checker.c  bonus/handle_error_2.c  bonus/linked_list_outils.c  bonus/operations_b.c  bonus/extra_operation.c  bonus/handle_error.c  bonus/operations_a.c  bonus/get_next_line/get_next_line.c  bonus/get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all

.SECONDARY: $(OBJS) 