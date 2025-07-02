/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:45:06 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/02 15:33:55 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	detect_duplicates(t_stack *stack_a)
{
	int		i;
	int		j;
	
	i = 1;
	j = 0;
	while (i < stack_a->size)
	{
		j = i + 1;
		while (j < (stack_a->size - 1))
		{
			
		}
	}
}

int	verify_integers(t_args *args)
{
	long	num;
	int		ac;
	char	**av;

	ac = args->new_ac;
	av = args->new_av;
	while (--ac > 0)
	{
		num = ft_atoi(av[ac]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
	}
	return (0);
}
void	handle_args(int ac, char **av, t_args *args)
{
	int		i;
	
	i = 0;
	args->new_ac = 0;
	if (ac == 2)
	{
		args->new_av = ft_split(av[1], ' ');
		while (args->new_av[args->new_ac])
			args->new_ac++;
	}
	else
	{
		args->new_ac = ac - 1;
		args->new_av = av + 1;
	}
}
int	verify_args(t_args *args)
{
	int		i;
	int		ac;
	char	**av;

	ac = args->new_ac;
	av = args->new_av;
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
