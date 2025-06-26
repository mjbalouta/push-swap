/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:20:15 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/26 11:24:44 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft-projects/get-next-line/get_next_line.h"
# include "./libft-projects/libft/libft.h"
# include "./libft-projects/printf/libftprintf.h"

typedef struct s_stack
{
	int	size;
	int	*numbers;
}				t_stack;


int		verify_args(int ac, char **av);
int		verify_integers(int ac, char **av);
int		*fill_stack(t_stack *stack_a, char **av);
void	select_algorithm(t_stack *stack_a);
void	sa(t_stack *stack_a);
void	ra(t_stack *stack_a);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);


#endif