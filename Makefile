# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 21:44:38 by mjoao-fr          #+#    #+#              #
#    Updated: 2025/06/25 21:44:38 by mjoao-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = cc
HEADER_FILE = includes
INCLUDES	= -I$(LIBFT_DIR)/libft -I$(LIBFT_DIR)/get-next-line -I$(LIBFT_DIR)/printf -I$(HEADER_FILE)
CFLAGS      = -Wall -Wextra -Werror $(INCLUDES) -g
NAME        = push_swap
SRCS = 		\
			srcs/main.c \
			srcs//operations/operations.c \
			srcs//sorting_algorithms/sorting_algorithms.c \
			srcs//utils/push_swap_utils.c \
			srcs//utils/push_swap_utils2.c \
			srcs//utils/bit_manipulation.c \
			srcs//validations/validate_args.c \
			srcs//sorting_algorithms/radix_sort.c \
			srcs//utils/free_mem.c
OBJS        = $(SRCS:.c=.o)
LIBFT_DIR   = ./libft-projects
LIBFT       = $(LIBFT_DIR)/complete_libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing objects..."
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing executable..."
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
