/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:22:19 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/29 21:12:23 by mjoao-fr         ###   ########.fr       */
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
