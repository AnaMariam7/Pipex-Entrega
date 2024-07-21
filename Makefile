NAME = pipex
SRC = main.c ft_print_errors.c ft_childs.c  ft_abs_rutes.c ft_rel_rutes.c 
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
RM = rm -rf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

TARGET = all

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ) pipex.dSYM
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean
	$(MAKE) $(TARGET)

sanitize: CFLAGS += -fsanitize=address
sanitize: CFLAGS += -g3
sanitize: re

.PHONY: re fclean clean all new  
