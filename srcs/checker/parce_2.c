/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:25:06 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		count_numbers(int argc, char **argv, t_stack_m *stack)
{
	int		i;
	int		j;
	char	**num_arr;
	int		count;
	int		height;

	count = 0;
	i = init_i(stack);
	if (argc == i + 1)
	{
		if ((num_arr = split_string(argv[i], &height)) == 0)
			return (-1);
		if ((j = parce_string_arg_num(num_arr, height)) == -1)
			return (-1);
		count += j;
		clean_up_map((void **)num_arr, height + 1);
	}
	else
	{
		if ((count = parse_arg_num(i, argc, argv)) == -1)
			return (-1);
	}
	return (count);
}

int		make_stack(int argc, char **argv, t_stack_m *stack)
{
	int		i;
	char	**num_arr;
	int		height;

	i = init_i(stack);
	if (argc == i + 1)
	{
		if ((num_arr = ft_strsplit(argv[i], ' ')) == 0)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		height = count_height(num_arr);
		if (fill_stack_a_str(num_arr, height, stack) == 0)
			return (0);
		clean_up_map((void **)num_arr, height + 1);
	}
	else
	{
		if (fill_stack_a(i, argv, argc, stack) == 0)
			return (0);
	}
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
