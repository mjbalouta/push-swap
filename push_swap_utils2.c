/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:35:11 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/06 13:42:24 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_largest_to_index(t_stack *stack_a)
{
	int	larger;
	int	i;
	int	index;
	int	j;
	int	z;
	int	exists;

	i = 0;
	z = 0;
	larger = INT_MIN;
	while(i < stack_a->size)
	{
		exists = 0;
		j = 0;
		while (j < stack_a->size - 1)
		{
			if (stack_a->numbers[i] == stack_a->checked[j])
				exists = 1;
			j++;
		}
		if (stack_a->numbers[i] > larger && exists == 0)
		{
			larger = stack_a->numbers[i];
			index = i;
			z++;
		}
		i++;
	}
	stack_a->checked[stack_a->checked_size] = larger;
	stack_a->checked_size++;
	return (index);
}

// int	find_largest(t_stack *stack_a, int size)
// {
// 	int	larger;
// 	int	i;
// 	int	index;

// 	i = 0;
// 	larger = INT_MIN;
// 	while(i < size)
// 	{
// 		if (stack_a->duplicate[i] > larger)
// 		{
// 			larger = stack_a->duplicate[i];
// 			index = i;
// 		}
// 		i++;
// 	}
// 	stack_a->largest = larger;
// 	return (index);
// }

// void	put_largest_last(t_stack *stack_a, int size)
// {
// 	int	i;
// 	int	temp;

// 	i = 0;
// 	stack_a->changed_dup = 0;
// 	while (i < size - 1)
// 	{
// 		if (stack_a->duplicate[i] == stack_a->largest)
// 		{
// 			temp = stack_a->duplicate[i + 1];
// 			stack_a->duplicate[i + 1] = stack_a->duplicate[i];
// 			stack_a->duplicate[i] = temp;
// 		}
// 		else
// 			i++;
// 	}
// }

// int	duplicate_stack(t_stack *stack_a)
// {
// 	int	i;
	
// 	i = 0;
// 	stack_a->duplicate = ft_calloc(stack_a->size, sizeof(int));
// 	if (!stack_a->duplicate)
// 		return (1);
// 	while (i < stack_a->size)
// 	{
// 		stack_a->duplicate[i] = stack_a->numbers[i];
// 		i++;
// 	}
// 	return (0);
// }

