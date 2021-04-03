/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_and_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/20 16:40:15 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*create_intarr(unsigned size)
{
	int *array;

	if ((array = (int *)ft_memalloc(sizeof(int) * size)) == 0)
		return (0);
	ft_bzero((void *)array, size);
	return (array);
}

void	clean_up_map(void **map, int height)
{
	int		i;

	i = 0;
	while (i < height)
	{
		ft_memdel(&map[i]);
		i++;
	}
	free((void *)map);
}

void	free_stacks(t_stack_m *stack)
{
	free((void *)stack->stack_a.arr);
	free((void *)stack->stack_b.arr);
	free((void *)stack->stack_a.id_index);
	free((void *)stack->stack_b.id_index);
	free((void *)stack->stack_a.subarray);
	free((void *)stack->stack_b.transpos);
}
