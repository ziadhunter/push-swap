NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory/chunk.c  mandatory/extra_outils.c  mandatory/hardcode.c  mandatory/operations_a.c  mandatory/push_swap.c  mandatory/sorting_algo.c  mandatory/extra_operation.c  mandatory/handle_input.c  mandatory/linked_list_outils.c  mandatory/operations_b.c  mandatory/set_indice_of_each_node.c
##BSRCS = 
OBJS = $(SRCS:.c=.o)
#BOBJS = $(BSRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

#bonus: $(BOBJS)
#	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJS) 