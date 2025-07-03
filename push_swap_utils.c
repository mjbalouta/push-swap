/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:22:19 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/03 15:00:34 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minor(t_stack *stack_a, int compare)
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
			if (compare == 1 && stack_a->numbers[i] != stack_a->minor)
			{
				minor = stack_a->numbers[i];
				index = i;
			}
			else if (compare == 0)
			{
				minor = stack_a->numbers[i];
				index = i;
			}
		}
		i++;
	}
	stack_a->minor = minor;
	return (index);
}
void	put_minor_first(t_stack *stack_a, int size, int compare)
{
	int	index;

	index = find_minor(stack_a, compare);
	if (index == 0)
		return ;
	if (index == size)
		rra(stack_a);
	else if (index >= (stack_a->size / 2) && stack_a->size == 4)
	{
		while (index-- > 0)
			rra(stack_a);
	}
	else if (index > (stack_a->size / 2) && stack_a->size == 5)
	{
		while (--index > 0)
			rra(stack_a);
	}
	else if (index <= (stack_a->size / 2))
	{
		while (index-- > 0)
			ra(stack_a);
	}
}

int	find_largest(t_stack *stack_a)
{
	int	larger;
	int	i;
	int	index;

	i = 0;
	larger = INT_MIN;
	while(i < stack_a->size)
	{
		if (stack_a->numbers[i] > larger)
		{
			larger = stack_a->numbers[i];
			index = i;
		}
		i++;
	}
	return (index);
}
int	define_nr_comparisons(t_stack *stack_a)
{
	int		index_larg;
	char	*binary_form;
	int		nr_digits;
	
	index_larg = find_largest(stack_a);
	binary_form = convert_to_binary(stack_a->numbers[index_larg]);
	nr_digits = ft_strlen(binary_form);
	free(binary_form);
	return (nr_digits);
}

int	is_sorted(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < (stack_a->size - 1))
	{
		if (stack_a->numbers[i] < stack_a->numbers[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}