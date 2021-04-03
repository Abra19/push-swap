/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_subsequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:49:11 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*create_length(int size)
{
	int		i;
	int		*length;

	i = 0;
	if ((length = (int *)ft_memalloc(sizeof(int) * size)) == 0)
		return (NULL);
	while (i < size)
	{
		length[i] = 1;
		i++;
	}
	return (length);
}

void	markup_length(int *length, int size, t_stack_m *stack)
{
	int		i;
	int		k;

	i = 1;
	while (i < size)
	{
		k = 0;
		while (k < i)
		{
			if (stack->stack_a.arr[i] > stack->stack_a.arr[k])
			{
				if (length[i] <= length[k])
					length[i] = length[k] + 1;
			}
			k++;
		}
		i++;
	}
}

int		found_subsize(int *length, int size, int *subsize)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (*subsize < length[i])
			*subsize = length[i];
		i++;
	}
	i = size - 1;
	while (i >= 0)
	{
		if (length[i] == *subsize)
			break ;
		i--;
	}
	return (i);
}

int		max_lenght_arr(t_stack_m *stack, int size)
{
	int		*length;
	int		i;
	int		tmp;
	int		subsize;

	length = create_length(size);
	markup_length(length, size, stack);
	subsize = 1;
	i = found_subsize(length, size, &subsize);
	tmp = length[i];
	stack->stack_a.subarray[i] = 1;
	while (i >= 0)
	{
		if (length[i] == tmp - 1)
		{
			stack->stack_a.subarray[i] = 1;
			tmp = length[i];
		}
		i--;
	}
	free((void *)length);
	return (subsize);
}
