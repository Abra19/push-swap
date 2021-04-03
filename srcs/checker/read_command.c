/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/24 18:06:46 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	command_pull(t_stack_m *stack, char *buffer)
{
	if (ft_strcmp(buffer, "ra") == 0)
		ra_command(stack);
	if (ft_strcmp(buffer, "rb") == 0)
		rb_command(stack);
	if (ft_strcmp(buffer, "rr") == 0)
		rr_command(stack);
	if (ft_strcmp(buffer, "rra") == 0)
		rra_command(stack);
	if (ft_strcmp(buffer, "rrb") == 0)
		rrb_command(stack);
	if (ft_strcmp(buffer, "rrr") == 0)
		rrr_command(stack);
	if (ft_strcmp(buffer, "sa") == 0)
		sa_command(stack);
	if (ft_strcmp(buffer, "sb") == 0)
		sb_command(stack);
	if (ft_strcmp(buffer, "ss") == 0)
		ss_command(stack);
	if (ft_strcmp(buffer, "pa") == 0)
		pa_command(stack);
	if (ft_strcmp(buffer, "pb") == 0)
		pb_command(stack);
}

int		read_command(t_stack_m *stack)
{
	char	*buffer;

	while (get_next_line(stack->fd, &buffer) > 0)
	{
		if (ft_strcmp(buffer, "ra") != 0 && ft_strcmp(buffer, "rb") != 0 &&\
		ft_strcmp(buffer, "rr") != 0 && ft_strcmp(buffer, "rra") != 0 &&\
		ft_strcmp(buffer, "rrb") != 0 && ft_strcmp(buffer, "rrr") != 0 &&\
		ft_strcmp(buffer, "pa") != 0 && ft_strcmp(buffer, "pb") != 0 &&\
		ft_strcmp(buffer, "sa") != 0 && ft_strcmp(buffer, "sb") != 0 &&\
		ft_strcmp(buffer, "ss") != 0)
		{
			ft_putendl_fd("Error", 2);
			free((void *)buffer);
			return (0);
		}
		else
			command_pull(stack, buffer);
		free((void *)buffer);
	}
	return (1);
}

void	stack_is_sorted(t_stack_m *stack)
{
	int		i;

	i = 1;
	while (i < stack->stack_a.size)
	{
		if (stack->stack_a.arr[i] < stack->stack_a.arr[i - 1])
		{
			ft_printf("KO\n");
			break ;
		}
		i++;
	}
	if (i == stack->stack_a.size && stack->shift == 0)
		ft_printf("OK\n");
}

void	num_of_commands(t_stack_m *stack, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp("-s", (const char *)argv[i]) == 0)
			ft_printf("total command's number = %d\n", stack->num_comm);
		i++;
	}
}

int		found_id_index_and_draw(t_stack_m *stack)
{
	if ((stack->stack_a.id_index = (int *)ft_memalloc(sizeof(int)\
	* stack->stack_a.size)) == 0 || (stack->stack_b.id_index = \
	(int *)ft_memalloc(sizeof(int) * stack->stack_b.size)) == 0)
	{
		free_stacks(stack);
		return (0);
	}
	init_index(&stack->stack_a, stack->stack_a.size);
	count_id_index(&stack->stack_a, stack->stack_a.size);
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
	{
		if (init_draw(stack) == 0)
			return (0);
		mlx_hook(stack->graf.mlx_win, 2, 0, key_press, stack);
		mlx_hook(stack->graf.mlx_win, 17, 0, close_x, stack);
	}
	else if (stack->draw == 1)
		ft_putendl("size of stack is too big for visualizer");
	print_start(stack, 0, 0, 0);
	return (1);
}
