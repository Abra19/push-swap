/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:15:44 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		*create_intarr(unsigned size)
{
	int *array;

	if ((array = (int *)ft_memalloc(sizeof(int) * size)) == 0)
		return (0);
	ft_bzero((void *)array, size);
	return (array);
}

int		init_stack(t_stack *stack)
{
	if ((stack->arr = create_intarr(stack->size)) == 0)
		return (0);
	return (1);
}

void	init_index(t_stack *stack, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		stack->id_index[i] = size - 1;
		i++;
	}
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
	free(map);
}

void	free_stacks(t_stack_m *stack)
{
	free(stack->stack_a.arr);
	free(stack->stack_b.arr);
	free(stack->stack_a.id_index);
	free(stack->stack_b.id_index);
}
