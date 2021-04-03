/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:41:51 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	count_id_index_current(t_stack_m *stack)
{
	int		j;

	init_index(&stack->stack_a, stack->stack_a.size - stack->shift);
	count_id_index(&stack->stack_a, stack->stack_a.size - stack->shift);
	j = stack->stack_a.size - stack->shift;
	while (j < stack->stack_a.size)
	{
		stack->stack_a.id_index[j] = 0;
		j++;
	}
	init_index(&stack->stack_b, stack->shift);
	count_id_index(&stack->stack_b, stack->shift);
	j = stack->shift;
	while (j < stack->stack_b.size)
	{
		stack->stack_b.id_index[j] = 0;
		j++;
	}
}

void	draw_row(t_stack_m *stack, int mult, int i)
{
	int		k;

	k = 0;
	image_pixel_put(stack, VBRIM, HBRIM + i, BORD);
	while (k < stack->stack_a.id_index[i / stack->grow_y] * stack->grow_x)
	{
		image_pixel_put(stack, VBRIM + (ADD - 10) / 2 + mult * k,\
		HBRIM + i, ACOL);
		k++;
	}
	image_pixel_put(stack, WIDTH / 2, HBRIM + i, BORD);
	k = 0;
	while (k < stack->stack_b.id_index[i / stack->grow_y] * stack->grow_x)
	{
		image_pixel_put(stack, WIDTH / 2 + (ADD - 10) / 2 + mult * k,\
		HBRIM + i, BCOL);
		k++;
	}
	image_pixel_put(stack, WIDTH - VBRIM, HBRIM + i, BORD);
}

void	count_scale(t_stack_m *stack)
{
	stack->grow_x = (WIDTH / 4) / stack->stack_a.size;
	stack->grow_y = (HEIGHT / 2) / stack->stack_a.size;
	if (stack->grow_x < 1)
		stack->grow_x = 1;
	if (stack->grow_y < 1)
		stack->grow_y = 1;
}

void	draw_bottom(t_stack_m *stack, int i)
{
	int		k;

	k = 0;
	while (k < WIDTH - 2 * VBRIM)
	{
		image_pixel_put(stack, VBRIM + 1 + k, HBRIM + i, BORD);
		k += stack->grow_x;
	}
}

int		visualize_sort(t_stack_m *stack)
{
	int		i;
	int		mult;

	i = 0;
	mult = 1;
	if (stack->stack_a.size < min_two_int((WIDTH / 2 - VBRIM) / 2 -\
	2 * ADD, HEIGHT / 2 - HBRIM - 2 * ADD))
		mult = 2;
	refresh_image(stack);
	count_id_index_current(stack);
	count_scale(stack);
	while (i < (stack->stack_a.size) * stack->grow_y)
	{
		draw_row(stack, mult, i);
		i += stack->grow_y;
	}
	draw_bottom(stack, i);
	mlx_put_image_to_window(stack->graf.mlx_ptr, stack->graf.mlx_win, \
	stack->graf.img_ptr, 0, HBRIM);
	mlx_do_sync(stack->graf.mlx_ptr);
	return (1);
}
