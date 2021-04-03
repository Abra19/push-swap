/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:22:23 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	count_id_index(t_stack *stack, int size)
{
	int		i;
	int		j;

	i = 0;
	if (size > 1)
	{
		while (i < size)
		{
			j = 0;
			while (j < size)
			{
				if (stack->arr[i] < stack->arr[j])
					stack->id_index[i] -= 1;
				j++;
			}
			i++;
		}
	}
	i = 0;
	while (i < size)
	{
		stack->sort_par += ft_abs(i - stack->id_index[i]);
		i++;
	}
}

void	print_usage(void)
{
	ft_printf("./checker [-options] list_of_int_without_double\n");
	ft_printf("option: -help\t - \t print usage\n");
	ft_printf("option: -v\t - \t show sorting process on STDOUT\n");
	ft_printf("          \t - \t first option is used\n");
	ft_printf("option: -c\t - \t only with option -v, second option\n");
	ft_printf("          \t - \t colour last operation\n");
	ft_printf("option: -s\t - \t print number of using commands\n");
	ft_printf("option: -f\t - \t write list of instructions from file\n");
	ft_printf("option: -m\t - \t visualize sorting process\n");
	ft_printf("          \t - \t used only with -f\n");
	ft_printf("          \t - \t -m first option is used, -f - second\n");
}

void	init_stacks(t_stack_m *stack)
{
	ft_bzero(stack, sizeof(t_stack_m));
	ft_bzero(&stack->stack_a, sizeof(t_stack));
	ft_bzero(&stack->stack_b, sizeof(t_stack));
	ft_bzero(&stack->graf, sizeof(t_graf));
	stack->num_comm = 1;
}

void	usage_with_exit(void)
{
	print_usage();
	exit(0);
}

int		main(int argc, char **argv)
{
	t_stack_m	stack;

	if (argc > 1)
	{
		init_stacks(&stack);
		work_with_options(&stack, argv, argc);
		if (parce_args(&stack, argc, argv) == 0)
			return (0);
		if (found_id_index_and_draw(&stack) == 0)
			return (0);
		if (read_command(&stack) == 0)
			return (0);
		stack_is_sorted(&stack);
		num_of_commands(&stack, argc, argv);
		if (stack.draw == 1 && stack.stack_a.size <\
		min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
			mlx_loop(stack.graf.mlx_ptr);
		free_stacks(&stack);
	}
	return (0);
}
