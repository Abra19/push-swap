/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:20:34 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		init_i(t_stack_m *stack)
{
	int		i;

	i = 1;
	if (stack->onearg == 1)
		i = 2;
	if (stack->twoarg == 1)
		i = 3;
	if (stack->threearg == 1)
		i = 4;
	if (stack->fourarg == 1)
		i = 5;
	return (i);
}

int		init_print(t_stack_m *stack, int n, int l, int num_s)
{
	int		m;

	m = stack->shift;
	stack->n = n;
	stack->l = l;
	stack->num_s = num_s;
	ft_printf("%w{yellow}|-----------|-----------|{eoc}\n", 1);
	return (m);
}

int		init_print_both(t_stack_m *stack, int n, int l)
{
	int		m;

	m = stack->shift;
	stack->n = n;
	stack->l = l;
	ft_printf("%w{yellow}|-----------|-----------|{eoc}\n", 1);
	return (m);
}

int		count_height(char **str)
{
	int		height;

	height = 0;
	while (str[height] != 0)
		height++;
	return (height);
}

void	init_image_parameter(t_stack_m *stack)
{
	stack->graf.width = WIDTH;
	stack->graf.height = HEIGHT;
	stack->graf.bpp = MAC_BPP * 8;
	stack->graf.size_line = stack->graf.width * MAC_BPP;
	stack->graf.endian = 0;
}
