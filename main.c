/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:20:03 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/26 11:08:08 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_integers(int ac, char **av)
{
	long	num;

	while (--ac > 0)
	{
		num = ft_atoi(av[ac]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
	}
	return (0);
}

int	verify_args(int ac, char **av)
{
	int	i;
	
	while (--ac > 0)
	{
		i = 0;
		while (av[ac][i])
		{
			if ((av[ac][i] == '-' || av[ac][i] == '+') || (av[ac][i] >= '0' && av[ac][i] <= '9'))
				i++;
			else
				return (1);
		}
	}
	return (0); 
}

int	*fill_stack(t_stack *stack_a, char **av)
{
	int	i;
	int	j;
	int	num;

	i = 1;
	j = 0;
	while (j < stack_a->size)
	{
		num = ft_atoi(av[i]);
		stack_a->numbers[j] = num;
		i++;
		j++;
	}
	return (stack_a->numbers);
}

void	select_algorithm(t_stack *stack_a)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	// if (stack_a->size == 3)
	// 	sort_three();
	// if (stack_a->size == 4 || stack_a->size == 5)
	// 	sort_four_five();
	// else
	// 	radix_sort();
}

int	main(int ac, char **av)
{	
	t_stack	stack_a;
	
	if (ac < 2)
		return (0);
	if (verify_args(ac, av) == 1)
		return (ft_printf("Error.\nOnly integers are allowed.\n"));
	if (verify_integers(ac, av) == 1)
		return (ft_printf("Error.\nOnly integers up to int_max and down to int_min allowed.\n"));
	stack_a.size = ac - 1;
	stack_a.numbers = ft_calloc(stack_a.size, sizeof(int));
	if (!stack_a.numbers)
		return (ft_printf("Error.\nCan't allocate memory.\n"));
	stack_a.numbers = fill_stack(&stack_a, av);
	select_algorithm(&stack_a);
	free(stack_a.numbers);
	return (0);
}
