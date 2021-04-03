/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/24 17:19:30 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		close_x(void *param)
{
	t_stack_m	*stack;

	stack = (t_stack_m *)param;
	mlx_clear_window(stack->graf.mlx_ptr, stack->graf.mlx_win);
	mlx_destroy_image(stack->graf.mlx_ptr, stack->graf.img_ptr);
	mlx_destroy_window(stack->graf.mlx_ptr, stack->graf.mlx_win);
	exit(0);
}

int		key_press(int key, void *param)
{
	t_stack_m	*stack;

	stack = (t_stack_m *)param;
	if (key == QUIT_KEY)
	{
		mlx_clear_window(stack->graf.mlx_ptr, stack->graf.mlx_win);
		mlx_destroy_image(stack->graf.mlx_ptr, stack->graf.img_ptr);
		mlx_destroy_window(stack->graf.mlx_ptr, stack->graf.mlx_win);
		exit(0);
	}
	return (1);
}

void	image_pixel_put(t_stack_m *stack, int x, int y, int color)
{
	int			point;

	if (x >= 0 && x < stack->graf.width && y >= 0 && \
		y < stack->graf.height)
	{
		point = MAC_BPP * (x + y * stack->graf.width);
		stack->graf.addr[point] = color;
		stack->graf.addr[++point] = color >> 8;
		stack->graf.addr[++point] = color >> 16;
	}
}

int		init_draw(t_stack_m *stack)
{
	init_image_parameter(stack);
	if ((stack->graf.mlx_ptr = mlx_init()) == NULL)
	{
		ft_putendl("start of drawing fall");
		return (0);
	}
	if ((stack->graf.mlx_win = mlx_new_window(stack->graf.mlx_ptr,\
	stack->graf.width, stack->graf.height, "push_swap visualizer")) == NULL)
	{
		ft_putendl("creating of new window fall");
		return (0);
	}
	if ((stack->graf.img_ptr = mlx_new_image(stack->graf.mlx_ptr,\
	stack->graf.width, stack->graf.height)) == NULL)
	{
		ft_putendl("creating of new image fall");
		return (0);
	}
	stack->graf.addr = mlx_get_data_addr(stack->graf.img_ptr,\
	&(stack->graf.bpp), &(stack->graf.size_line), &(stack->graf.endian));
	ft_bzero(stack->graf.addr,\
	stack->graf.width * stack->graf.height * MAC_BPP);
	return (1);
}

int		refresh_image(t_stack_m *stack)
{
	char	*tmp;

	mlx_destroy_image(stack->graf.mlx_ptr, stack->graf.img_ptr);
	mlx_clear_window(stack->graf.mlx_ptr, stack->graf.mlx_win);
	mlx_string_put(stack->graf.mlx_ptr, stack->graf.mlx_win,\
	(WIDTH / 2 + VBRIM) / 2 - 3, 0, 0xff007f, "STACK A");
	mlx_string_put(stack->graf.mlx_ptr, stack->graf.mlx_win,\
	3 * WIDTH / 4 - VBRIM / 2 - 3, 0, 0x0000ff, "STACK B");
	mlx_string_put(stack->graf.mlx_ptr, stack->graf.mlx_win,\
	20, 20, 0x008000, "number of operations:");
	mlx_string_put(stack->graf.mlx_ptr, stack->graf.mlx_win,\
	280, 20, 0x008000, (tmp = ft_itoa(stack->num_comm)));
	free(tmp);
	if ((stack->graf.img_ptr = mlx_new_image(stack->graf.mlx_ptr,\
	stack->graf.width, stack->graf.height)) == NULL)
	{
		ft_putendl("creating of new image fall");
		return (0);
	}
	stack->graf.addr = mlx_get_data_addr(stack->graf.img_ptr,\
	&(stack->graf.bpp), &(stack->graf.size_line), &(stack->graf.endian));
	ft_bzero(stack->graf.addr,\
	stack->graf.width * stack->graf.height * MAC_BPP);
	return (1);
}
