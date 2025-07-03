/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:13:39 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/03 12:13:31 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	get_bit(int number, int nr_comp, int digit)
{
	char	*nr;
	int		i;
	char	bit;

	i = nr_comp - 1;
	nr = ft_calloc(nr_comp, sizeof(char));
	nr[nr_comp] = '\0';
	if (!nr)
		return ('0');
	while (i >= 0)
	{
		nr[i] = (number % 2) + '0';
		number = number / 2;
		i--;
	}
	bit = nr[digit];
	free(nr);
	return (bit);
}

int	count_digits(int num)
{
	int	count;
	
	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 2;
		count++;
	}
	return (count);
}

char	*convert_to_binary(int num)
{
	char	*nr;
	int		i;

	i = count_digits(num) - 1;
	nr = ft_calloc(i + 2, sizeof(unsigned char));
	nr[i + 1] = '\0';
	if (!nr)
		return (NULL);
	while (i >= 0)
	{
		nr[i] = (num % 2) + '0';
		num = num / 2;
		i--;
	}
	return (nr);
}


