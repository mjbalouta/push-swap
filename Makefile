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
CFLAGS      = -Wall -Wextra -Werror -I$(LIBFT_DIR) -g
NAME        = push_swap
SRCS        = main.c operations.c sorting_algorithms.c push_swap_utils.c push_swap_utils2.c bit_manipulation.c validate_args.c radix_sort.c free_mem.c
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
