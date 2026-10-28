CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make
NAME = push_swap
CHECKER = checker
SRC_DIR = src
INC_DIR = include
BONUS_DIR = bonus
SRC = $(SRC_DIR)/push_swap.c \
      $(SRC_DIR)/utils.c \
      $(SRC_DIR)/input_checker.c \
      $(SRC_DIR)/input_parser.c \
      $(SRC_DIR)/instructions.c \
      $(SRC_DIR)/instructions_wrappers/instructions_wrappers.c \
      $(SRC_DIR)/instructions_wrappers/instructions_wrappers_2.c \
      $(SRC_DIR)/algorithm/algorithm.c \
      $(SRC_DIR)/algorithm/algorithm_2.c \
      $(SRC_DIR)/algorithm/algorithm_3.c \
      $(SRC_DIR)/cache.c \
      $(SRC_DIR)/chunking/chunking.c \
      $(SRC_DIR)/chunking/chunking_2.c \
      $(SRC_DIR)/stack.c
OBJ = $(SRC:.c=.o)
FTPRINTF_DIR = ftprintf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a
GNL_DIR = get_next_line
SRC_BONUS = $(BONUS_DIR)/checker_bonus.c \
	    $(SRC_DIR)/utils.c \
	    $(SRC_DIR)/input_checker.c \
	    $(SRC_DIR)/input_parser.c \
	    $(SRC_DIR)/instructions.c \
	    $(SRC_DIR)/stack.c \
	    $(BONUS_DIR)/reader_bonus.c \
	    $(BONUS_DIR)/instr_checker_bonus.c \
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
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(BONUS_DIR) -I$(FTPRINTF_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -f $(CHECKER)
	rm -f $(NAME)
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re:	fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
