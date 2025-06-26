/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:06:44 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/26 11:33:36 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->numbers[0];
	stack_a->numbers[0] = stack_a->numbers[1];
	stack_a->numbers[1] = temp;
}

void	ra(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->numbers[2];
	stack_a->numbers[2] = stack_a->numbers[1];
	stack_a->numbers[1] = stack_a->numbers[0];
	stack_a->numbers[0] = temp;	
}

// void	sb(t_stack *stack_b)
// {
// 	int	temp;

// 	temp = stack_b[0];
// 	stack_b[0] = stack_b[1];
// 	stack_b[1] = temp;
// }

// void	pa(int *stack_a, int *stack_b)
// {
// 	int	to_push;
// 	int	temp;
	
// 	stack_b[0] = to_push;
	
// }