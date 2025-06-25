/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:20:03 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/25 20:33:55 by mjoao-fr         ###   ########.fr       */
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

int	main(int ac, char **av)
{	
	if (ac < 2)
		return (0);
	if (verify_args(ac, av) == 1)
		return (ft_printf("Error.\nOnly integers are allowed."));
	if (verify_integers(ac, av) == 1)
		return (ft_printf("Error.\nOnly integers up to int_max and down to int_min allowed."));
	return (0);
}