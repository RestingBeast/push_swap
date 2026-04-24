CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make
NAME = push_swap
CHECKER = checker
SRC = push_swap.c \
      utils.c \
      input_checker.c \
      input_parser.c \
      instructions.c \
      instructions_wrappers.c \
      instructions_wrappers_2.c \
      algorithm.c \
      algorithm_2.c \
      algorithm_3.c \
      cache.c \
      chunking.c \
      chunking_2.c \
      stack.c
OBJ = $(SRC:.c=.o)
FTPRINTF_DIR = ftprintf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a
GNL_DIR = get_next_line
SRC_BONUS = checker_bonus.c \
	    utils.c \
	    input_checker.c \
	    input_parser.c \
	    instructions.c \
	    stack.c \
	    reader_bonus.c \
	    instr_checker_bonus.c \
	    $(GNL_DIR)/get_next_line.c \
	    $(GNL_DIR)/get_next_line_utils.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all:	$(FTPRINTF) $(NAME)

bonus:	$(FTPRINTF) $(CHECKER)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTF_DIR)

$(CHECKER): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(FTPRINTF) -o $(CHECKER)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FTPRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(FTPRINTF_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -f $(CHECKER)
	rm -f $(NAME)
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re:	fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus
