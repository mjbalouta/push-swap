/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:28:56 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/04 19:39:11 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_by_stacks(t_stack *stack_a, t_stack *stack_b, int nr_comp, int digit)
{
	int		i;
	int		size;
	char	bit;

	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		bit = get_bit(stack_a->numbers[0], nr_comp, digit);
		if (bit == '0')
			pb(stack_a, stack_b);
		else if (bit == '1')
			ra(stack_a);
		i++;
	}
}

int	fill_index(t_stack *stack_a)
{
	int	index;
	int	i;

	i = stack_a->size - 1;
	stack_a->checked_size = 0;
	stack_a->checked = ft_calloc(stack_a->size, sizeof(int));
	if (!stack_a->checked)
		return (-1);
	while (i > 0)
	{
		index = find_largest(stack_a);
		if (index == -1)
			return (1);
		stack_a->index[index] = i;
		i--;
	}
	i = 0;
	while (i < stack_a->size)
		ft_printf("%d ", stack_a->index[i++]);
	free(stack_a->checked);
	return (0);
}

int	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	
	(void)stack_b;
	// int		nr_comp;
	int		i;
	// int		digit;

	// nr_comp = define_nr_comparisons(stack_a);
	stack_a->index = ft_calloc(stack_a->size, sizeof(int));
	if (!stack_a->index)
		return (1);
	// duplicate_stack(stack_a);
	if (fill_index(stack_a) == 1)
		return (1);
	// digit = nr_comp;
	// while (digit >= 0)
	// {
	// 	divide_by_stacks(stack_a, stack_b, nr_comp, digit);
	// 	i = stack_b->size - 1;
	// 	while (i >= 0)
	// 	{
	// 		pa(stack_a, stack_b);
	// 		i--;
	// 	}
	// 	digit--;
	// }
	// ft_printf("\nstack_a after: ");
	return (0);
	i = 0;
	while (i < stack_a->size)
		ft_printf("%d ", stack_a->index[i++]);
	
	// ft_printf("\nstack_b after: ");
	// i = 0;
	// while (i < stack_b->size)
	// 	ft_printf("%d ,", stack_b->numbers[i++]);
}

