/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:33:08 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/07 15:33:17 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_memory(t_stack *stack_a, t_args *args)
{
	if (stack_a->numbers)
		free(stack_a->numbers);
	free_args(args);
}

void	free_args(t_args *args)
{
	int	i;

	i = -1;
	if (args->changed == 1)
	{
		while (++i < args->new_ac)
			free(args->new_av[i]);
		free(args->new_av);
	}
}

void	free_binary(t_stack *stack_a)
{
	int	i;

	i = 0;
	if (!stack_a->binary)
		return ;
	while (i < stack_a->size)
	{
		free(stack_a->binary[i]);
		i++;
	}
	free(stack_a->binary);
	stack_a->binary = NULL;
}
