/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:06:44 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/30 20:25:56 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->numbers[0];
	stack_a->numbers[0] = stack_a->numbers[1];
	stack_a->numbers[1] = temp;
	ft_printf("sa\n");
	ft_printf("%d, ", stack_a->numbers[0]);
	ft_printf("%d, ", stack_a->numbers[1]);
	ft_printf("%d, ", stack_a->numbers[2]);
	ft_printf("%d, ", stack_a->numbers[3]);
	ft_printf("%d\n", stack_a->numbers[4]);
}

void	rra(t_stack *stack_a)
{
	int	temp;
	int	temp2;
	int	i;

	i = 0;
	temp = stack_a->numbers[0];
	stack_a->numbers[0] = stack_a->numbers[stack_a->size - 1];
	while (i < stack_a->size - 1)
	{
		temp2 = stack_a->numbers[i + 1];
		stack_a->numbers[i + 1] = temp;
		temp = temp2;
		i++;
	}
	ft_printf("rra\n");
	ft_printf("%d, ", stack_a->numbers[0]);
	ft_printf("%d, ", stack_a->numbers[1]);
	ft_printf("%d, ", stack_a->numbers[2]);
	ft_printf("%d, ", stack_a->numbers[3]);
	ft_printf("%d\n", stack_a->numbers[4]);
}

void	ra(t_stack *stack_a)
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
	ft_printf("ra\n");
	ft_printf("%d, ", stack_a->numbers[0]);
	ft_printf("%d, ", stack_a->numbers[1]);
	ft_printf("%d, ", stack_a->numbers[2]);
	ft_printf("%d, ", stack_a->numbers[3]);
	ft_printf("%d\n", stack_a->numbers[4]);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	i;
	int	temp2;
	
	stack_b->size++;
	if (stack_b->size == 1)
		stack_b->numbers[0] = stack_a->numbers[0];
	else
	{
		i = 0;
		temp = stack_a->numbers[stack_a->size - 1];		
		while (i < stack_b->size)
		{
			temp2 = stack_b->numbers[i];
			stack_b->numbers[i] = temp;
			temp = temp2;
			i++;
		}
	}
	stack_a->numbers[0] = 0;
	if (stack_a->size > 1)
		ra(stack_a);
	stack_a->size--;
	// ft_printf("PB:\n");
	// ft_printf("a: %d, ", stack_a->numbers[0]);
	// ft_printf("%d, ", stack_a->numbers[1]);
	// ft_printf("%d, ", stack_a->numbers[2]);
	// ft_printf("%d, \n", stack_a->numbers[3]);
	// ft_printf("b: %d, ", stack_b->numbers[0]);
	// ft_printf("%d\n", stack_b->numbers[1]);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	i;
	int	temp2;
	
	stack_a->size++;
	if (stack_a->size == 1)
		stack_a->numbers[0] = stack_b->numbers[0];
	else
	{
		i = 0;
		temp = stack_b->numbers[stack_b->size - 1];		
		while (i < stack_a->size)
		{
			temp2 = stack_a->numbers[i];
			stack_a->numbers[i] = temp;
			temp = temp2;
			i++;
		}
	}
	stack_b->numbers[0] = 0;
	if (stack_a->size > 1)
		ra(stack_b);
	stack_b->size--;
	// ft_printf("PB:\n");
	// ft_printf("a: %d, ", stack_a->numbers[0]);
	// ft_printf("%d, ", stack_a->numbers[1]);
	// ft_printf("%d, ", stack_a->numbers[2]);
	// ft_printf("%d, \n", stack_a->numbers[3]);
	// ft_printf("b: %d, ", stack_b->numbers[0]);
	// ft_printf("%d\n", stack_b->numbers[1]);
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