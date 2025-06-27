/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:54:41 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/27 18:35:33 by mjoao-fr         ###   ########.fr       */
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
		if (stack_a->numbers[0] > stack_a->numbers[1])
		{	
			swapped = 1;
			sa(stack_a);
			
		}
		if (stack_a->numbers[1] > stack_a->numbers[2])
		{
			swapped = 1;
			ra(stack_a);
		}
	}
}

void	sort_four_five(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	
	index = find_minor(stack_a);
	while ((index + 1) > 0)
	{
		rsa(stack_a);
		index--;
	}
	pb(stack_a, stack_b);
	//FIQUEI AQUIIIIIIII
	// ft_printf("%d ,", stack_a->numbers[0]);
	// ft_printf("%d ,", stack_a->numbers[1]);
	// ft_printf("%d ,", stack_a->numbers[2]);
	// ft_printf("%d \n", stack_a->numbers[3]);
	(void)stack_b;
}
