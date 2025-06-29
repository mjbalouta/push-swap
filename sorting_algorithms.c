/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:54:41 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/30 00:30:31 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a->numbers[0] > stack_a->numbers[1])
		sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	int	swapped;

	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		if (stack_a->numbers[1] < stack_a->numbers[2])
		{	
			swapped = 1;
			sa(stack_a);
			
		}
		if (stack_a->numbers[0] < stack_a->numbers[2] || stack_a->numbers[0] < stack_a->numbers[1])
		{
			swapped = 1;
			rsa(stack_a);
		}
	}
	// ft_printf("%d, ", stack_a->numbers[0]);
	// ft_printf("%d, ", stack_a->numbers[1]);
	// ft_printf("%d\n", stack_a->numbers[2]);
}

void	sort_four_five(t_stack *stack_a, t_stack *stack_b)
{	
	if (stack_a->size == 4)
	{
		put_minor_on_top(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	else if (stack_a->size == 5)
	{
		put_minor_on_top(stack_a);
		pb(stack_a, stack_b);
		put_minor_on_top(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	ft_printf("\nstack_a after: ");
	ft_printf("%d ,", stack_a->numbers[0]);
	ft_printf("%d ,", stack_a->numbers[1]);
	ft_printf("%d ,", stack_a->numbers[2]);
	ft_printf("%d ,", stack_a->numbers[3]);
	ft_printf("%d \n", stack_a->numbers[4]);
	ft_printf("\nstack_b after: ");
	ft_printf("%d ,", stack_b->numbers[0]);
	ft_printf("%d ,", stack_b->numbers[1]);
	(void)stack_b;
}
