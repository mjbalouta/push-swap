/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:35:11 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/02 21:44:46 by mjoao-fr         ###   ########.fr       */
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