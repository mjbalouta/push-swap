/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:54:41 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/26 11:34:34 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a->numbers[0] > stack_a->numbers[1])
	{
		sa(stack_a);
		ft_printf("sa\n");
	}
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
			ft_printf("sa\n");
		}
		if (stack_a->numbers[1] > stack_a->numbers[2])
		{
			swapped = 1;
			ra(stack_a);
			ft_printf("ra\n");
		}
	}
}
