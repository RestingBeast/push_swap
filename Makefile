CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
