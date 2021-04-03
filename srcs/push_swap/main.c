/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/22 21:28:15 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_usage(void)
{
	ft_printf("./push_swap [-options] list_of_int_without_double\n");
	ft_printf("option: -f   \t - \t print list of instructions in file\n");
	ft_printf("option: -s   \t - \t print number of using commands\n");
	ft_printf("option: -help\t - \t print usage\n");
}

int		parce_arg(t_stack_m *stack, int argc, char **argv)
{
	if ((stack->stack_a.size = count_numbers(argc, argv, stack)) == -1)
		return (0);
	stack->stack_b.size = stack->stack_a.size;
	if (init_stack(&stack->stack_a) == 0)
		return (0);
	if (init_stack(&stack->stack_b) == 0)
	{
		free(stack->stack_a.arr);
		return (0);
	}
	if (make_stack(argc, argv, stack) == 0)
	{
		free_stacks(stack);
		return (0);
	}
	if (check_double(&stack->stack_a) == 0)
	{
		free_stacks(stack);
		return (0);
	}
	stack->stack_a.bottom = max_int_array(stack->stack_a.arr,\
	stack->stack_a.size);
	return (1);
}

int		count_sort_ind(t_stack_m *stack)
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
	stack->sort_par = stack->stack_a.sort_par;
	return (1);
}

int		check_double(t_stack *stack)
{
	int		i;
	int		j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->arr[i] == stack->arr[j])
			{
				ft_putendl_fd("Error", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack_m stack;

	if (argc > 1)
	{
		init_stacks(&stack);
		parce_option(&stack, argc, argv);
		if (parce_arg(&stack, argc, argv) == 0)
			return (1);
		if (count_sort_ind(&stack) == 0)
			return (1);
		if (stack.sort_par != 0)
		{
			if (sorter(&stack) == 0)
				return (1);
		}
		if (argc > 2)
		{
			if (ft_strcmp("-s", (const char *)argv[1]) == 0 ||
			ft_strcmp("-s", (const char *)argv[2]) == 0)
				ft_printf("total command's number = %d\n", stack.num_comm);
		}
		free_stacks(&stack);
	}
	return (0);
}
