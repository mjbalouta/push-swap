/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:20:03 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/07 14:01:06 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_stack(t_stack *stack_a, t_args *args)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	while (j < stack_a->size)
	{
		num = ft_atoi(args->new_av[i]);
		stack_a->numbers[j] = num;
		i++;
		j++;
	}
	return (stack_a->numbers);
}

int	select_algorithm(t_stack *stack_a)
{
	t_stack	stack_b;

	if (is_sorted(stack_a) == 0)
		return (0);
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a); 
	else
	{
		stack_b.numbers = ft_calloc(stack_a->size, sizeof(int));
		stack_b.size = 0;
		if (!stack_b.numbers)
			return (1);
		if (stack_a->size == 4 || stack_a->size == 5)
			sort_four_five(stack_a, &stack_b);
		else
		{
			if (radix_sort(stack_a, &stack_b) == 1)
				return (1);
		}
		free(stack_b.numbers);
	}
	return (0);
}

int	main(int ac, char **av)
{	
	t_stack	stack_a;
	t_args	args;
	
	if (ac < 2)
		return (0);
	if (handle_args(ac, av, &args) == 1)
		return (free_args(&args), 0);
	if (verify_args(&args) == 1)
		return (free_args(&args), ft_printf("Error\nInvalid args.\n"));
	if (verify_integers(&args) == 1)
		return (free_args(&args), ft_printf("Error\nOnly integers up to int_max and down to int_min allowed.\n"));
	stack_a.size = args.new_ac;
	stack_a.numbers = ft_calloc(stack_a.size, sizeof(int));
	if (!stack_a.numbers)
		return (ft_printf("Error\nCan't allocate memory.\n"));
	stack_a.numbers = fill_stack(&stack_a, &args);
	if (detect_duplicates(&stack_a) == 1)
		return (free_memory(&stack_a, &args), ft_printf("Error\nDuplicates are not allowed.\n"));
	if (select_algorithm(&stack_a) == 1)
		return (free_memory(&stack_a, &args), ft_printf("Error\nCan't allocate memory.\n"));
	free_memory(&stack_a, &args);
	return (0);
}
