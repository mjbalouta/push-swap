/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:35:11 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/07 15:42:55 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	exists_in_checked(t_stack *stack_a, int i)
{
	int	j;

	j = 0;
	while (j < stack_a->checked_size)
	{
		if (stack_a->numbers[i] == stack_a->checked[j])
			return (1);
		j++;
	}
	return (0);
}

int	find_largest_to_index(t_stack *stack_a)
{
	int	larger;
	int	i;
	int	index;
	int	z;

	i = 0;
	z = 0;
	larger = INT_MIN;
	while (i < stack_a->size)
	{
		if (exists_in_checked(stack_a, i) == 0)
		{
			if (stack_a->numbers[i] > larger)
			{
				larger = stack_a->numbers[i];
				index = i;
				z++;
			}
		}
		i++;
	}
	stack_a->checked[stack_a->checked_size] = larger;
	stack_a->checked_size++;
	return (index);
}

int	count_digits(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 2;
		count++;
	}
	return (count);
}
