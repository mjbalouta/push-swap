/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:22:19 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/30 10:58:21 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minor(t_stack *stack_a)
{
	int	minor;
	int	i;
	int	index;

	i = 0;
	minor = INT_MAX;
	while(i < stack_a->size)
	{
		if (stack_a->numbers[i] < minor)
		{
			minor = stack_a->numbers[i];
			index = i;
		}
		i++;
	}
	// ft_printf("minor: %d\nindex: %d\n", minor, index);
	return (index);
}
void	put_minor_on_top(t_stack *stack_a)
{
	int	index;

	index = find_minor(stack_a);
	if (index == stack_a->size - 1)
		return ;
	if (index >= (stack_a->size / 2) && stack_a->size == 4)
	{
		while (--index > 0)
			ra(stack_a);
	}
	else if (index > (stack_a->size / 2) && stack_a->size == 5)
	{
		while (--index > 1)
			ra(stack_a);
	}
	else if (index == (stack_a->size / 2) && stack_a->size == 5)
	{
		while (--index >= 0)
			ra(stack_a);
	}
	else if (index < (stack_a->size / 2))
	{
		while (index-- >= 0)
			rsa(stack_a);
	}
}

