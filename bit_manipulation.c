/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:13:39 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/07/07 13:41:14 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_binary_array(t_stack *stack_a)
{
	int		i;
	char	*binary_form;
	int		nr_digits;

	i = 0;
	stack_a->binary = ft_calloc(stack_a->size + 1, sizeof(char *));
	if (!stack_a->binary)
		return (1);
	while (i < stack_a->size)
	{
		binary_form = convert_to_binary(stack_a->index[i]);
		nr_digits = ft_strlen(binary_form);
		stack_a->binary[i] = ft_calloc(nr_digits + 1, sizeof(char));
		if (!stack_a->binary[i])
			return (-1);
		ft_strlcpy(stack_a->binary[i], binary_form, nr_digits + 1);
		free(binary_form);
		i++;
	}
	return (0);
}

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
	return (bit);
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


