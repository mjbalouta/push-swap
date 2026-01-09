/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:28:56 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/07 16:50:15 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_index(t_stack *stack_a)
{
	int	index;
	int	i;

	i = stack_a->size - 1;
	stack_a->checked_size = 0;
	stack_a->checked = ft_calloc(stack_a->size, sizeof(int));
	if (!stack_a->checked)
		return (-1);
	while (i >= 0)
	{
		index = find_largest_to_index(stack_a);
		if (index == -1)
			return (1);
		stack_a->index[index] = i;
		i--;
	}
	free(stack_a->checked);
	return (0);
}

void	divide_by_stacks(t_stack *stack_a, t_stack *stack_b, int iterations)
{
	int		i;
	int		size;
	char	bit;

	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		bit = get_bit(stack_a->binary[i], iterations);
		if (bit == '1')
			ra(stack_a);
		else if (bit == '0')
			pb(stack_a, stack_b);
		i++;
	}
	i = 0;
}

void	sorting(t_stack *stack_a, t_stack *stack_b, int j)
{
	int	i;

	i = 0;
	divide_by_stacks(stack_a, stack_b, j);
	i = stack_b->size;
	while (i > 0)
	{
		pa(stack_a, stack_b);
		i--;
	}
}

int	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		nr_comp;
	int		j;

	stack_a->index = ft_calloc(stack_a->size, sizeof(int));
	if (!stack_a->index)
		return (1);
	if (fill_index(stack_a) == 1)
		return (1);
	fill_binary_array(stack_a);
	nr_comp = define_nr_comparisons(stack_a);
	if (nr_comp == -1)
		return (1);
	j = -1;
	while (++j < nr_comp)
	{
		sorting(stack_a, stack_b, j);
		if (fill_index(stack_a) == 1)
			return (1);
		free_binary(stack_a);
		fill_binary_array(stack_a);
	}
	free(stack_a->index);
	free_binary(stack_a);
	return (0);
}
