/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:54:41 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/04 11:17:16 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a->numbers[0] > stack_a->numbers[1])
		sa(stack_a);
	// ft_printf("%d, ", stack_a->numbers[0]);
	// ft_printf("%d, ", stack_a->numbers[1]);
}

void	sort_three(t_stack *stack_a)
{
	int	index;
	
	index = find_minor(stack_a);
	if (index == 1 && (is_sorted(stack_a) != 0))
		sa(stack_a);
	if (index == 2 && (is_sorted(stack_a) != 0))
		rra(stack_a);
	if (stack_a->numbers[1] > stack_a->numbers[2] && (is_sorted(stack_a) != 0))
	{
		rra(stack_a);
		sa(stack_a);
	}
	// ft_printf("%d, ", stack_a->numbers[0]);
	// ft_printf("%d, ", stack_a->numbers[1]);
	// ft_printf("%d\n", stack_a->numbers[2]);
}

void	sort_four_five(t_stack *stack_a, t_stack *stack_b)
{	
	if (stack_a->size == 4)
	{
		put_minor_first(stack_a, stack_a->size - 1);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	else if (stack_a->size == 5)
	{
		put_minor_first(stack_a, stack_a->size - 1);
		pb(stack_a, stack_b);
		put_minor_first(stack_a, stack_a->size - 1);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	int	i;
	i = 0;
	while (i < stack_a->size)
		ft_printf("%d ", stack_a->numbers[i++]);
}

