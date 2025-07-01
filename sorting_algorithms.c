/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:54:41 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/01 17:38:57 by mjoao-fr         ###   ########.fr       */
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
	if (index == 1)
		sa(stack_a);
	if (index == 2)
		rra(stack_a);
	if (stack_a->numbers[1] > stack_a->numbers[2])
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
		put_minor_first(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	else if (stack_a->size == 5)
	{
		put_minor_first(stack_a);
		pb(stack_a, stack_b);
		put_minor_first(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	// ft_printf("%d, ", stack_a->numbers[0]);
	// ft_printf("%d, ", stack_a->numbers[1]);
	// ft_printf("%d, ", stack_a->numbers[2]);
	// ft_printf("%d, ", stack_a->numbers[3]);
	// ft_printf("%d\n", stack_a->numbers[4]);
}
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

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		nr_comp;
	int		i;
	int		digit;

	nr_comp = define_nr_comparisons(stack_a);
	digit = nr_comp;
	while (digit >= 0)
	{
		divide_by_stacks(stack_a, stack_b, nr_comp, digit);
		i = stack_b->size - 1;
		while (i >= 0)
		{
			pa(stack_a, stack_b);
			i--;
		}
		digit--;
	}
	ft_printf("\nstack_a after: ");
	i = 0;
	while (i < stack_a->size)
		ft_printf("%d ", stack_a->numbers[i++]);
	
	ft_printf("\nstack_b after: ");
	i = 0;
	while (i < stack_b->size)
		ft_printf("%d ,", stack_b->numbers[i++]);
}
