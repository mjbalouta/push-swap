/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:13:39 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/30 17:18:50 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_bit(int number, int position)
{
    return ((number >> position) & 1);
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
	nr = ft_calloc(i + 1, sizeof(unsigned char));
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


