/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:06:44 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/27 18:35:18 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;
	int	last;

	if (stack_a->size < 2)
		return ;
	last = stack_a->size - 1;
	temp = stack_a->numbers[last];
	stack_a->numbers[last] = stack_a->numbers[last - 1];
	stack_a->numbers[last - 1] = temp;
	ft_printf("sa\n");
}

void	ra(t_stack *stack_a)
{
	int	temp;
	int	temp2;
	int	i;

	i = 0;
	temp = stack_a->numbers[0];
	stack_a->numbers[0] = stack_a->numbers[stack_a->size - 1];
	while (i < stack_a->size)
	{
		temp2 = stack_a->numbers[i + 1];
		stack_a->numbers[i + 1] = temp;
		temp = temp2;
		i++;
	}
	ft_printf("ra\n");
}

void	rsa(t_stack *stack_a)
{
	int	temp;
	int	temp2;
	int	last;

	last = stack_a->size - 1;
	temp = stack_a->numbers[last];
	stack_a->numbers[last] = stack_a->numbers[0];
	while (last > 0)
	{
		temp2 = stack_a->numbers[last - 1];
		stack_a->numbers[last - 1] = temp;
		temp = temp2;
		last--;
	}
	ft_printf("rsa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("before:\n");
	ft_printf("stack a:\n");
	ft_printf("%d ,%d ,%d ,%d\n", stack_a->numbers[0], stack_a->numbers[1], stack_a->numbers[2], stack_a->numbers[3]);
	ft_printf("stack b:\n");
	ft_printf("%d ,%d ,%d ,%d\n", stack_b->numbers[0], stack_b->numbers[1], stack_b->numbers[2], stack_b->numbers[3]);
	stack_b->size += 1;
	stack_b->numbers[stack_b->size - 1] = stack_a->numbers[stack_a->size - 1];
	stack_a->size -= 1;
	ft_printf("after:\n");
	ft_printf("stack a:\n");
	ft_printf("%d ,%d ,%d ,%d\n", stack_a->numbers[0], stack_a->numbers[1], stack_a->numbers[2], stack_a->numbers[3]);
	ft_printf("stack b:\n");
	ft_printf("%d ,%d ,%d ,%d\n", stack_b->numbers[0], stack_b->numbers[1], stack_b->numbers[2], stack_b->numbers[3]);
	ft_printf("pb\n");
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