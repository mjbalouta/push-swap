/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:13:39 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/05 23:15:06 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	get_bit(char *number, int iterations)
{
	int		nr_digits;
	char	bit;
	int		position;

	nr_digits = ft_strlen(number);
	iterations += 1;
	position = nr_digits - iterations;
	if (position < 0)
		bit = '0';
	else
		bit = number[position];
	
	// if (nr_digits == digits)
	// {
	// 	position = nr_digits - 1 - iterations;
	// 	if (position < 0)
	// 		bit = '0';
	// 	else
	// 		bit = number[nr_digits - 1 - iterations];
	// }
	// else
	// {
	// 	position = nr_digits - 1;
	// 	if (position < 0)
	// 		bit = '0';
	// 	else
	// 		bit = number[nr_digits - 1];
	// }
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


