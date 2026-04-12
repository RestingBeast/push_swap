CC = cc
MAKE = make
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c \
      utils.c \
	  input_checker.c \
      input_parser.c
OBJ = $(SRC:.c=.o)
FTPRINTF_DIR = ftprintf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

all:	$(FTPRINTF) $(NAME)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTF_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(FTPRINTF_DIR) -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(FTPRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re
