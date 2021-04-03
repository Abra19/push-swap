/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:51:19 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_string(char *str, int *height)
{
	char **num_arr;

	if ((num_arr = ft_strsplit(str, ' ')) == NULL)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	*height = count_height(num_arr);
	return (num_arr);
}

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

void	compare_option(char **argv, t_stack_m *stack, int argc)
{
	if (argc > 2)
	{
		if ((ft_strcmp("-f", (const char *)argv[1]) == 0 &&\
		ft_strcmp("-s", (const char *)argv[2]) == 0) ||\
		(ft_strcmp("-s", (const char *)argv[1]) == 0 && \
		ft_strcmp("-f", (const char *)argv[2]) == 0))
		{
			if (ft_strcmp((const char *)argv[1], (const char *)argv[2]) == 0)
			{
				print_usage();
				exit(0);
			}
		}
		if (ft_strcmp("-f", (const char *)argv[1]) == 0 ||
		ft_strcmp("-f", (const char *)argv[2]) == 0)
			stack->fd = open("./test.c", O_RDWR | O_CREAT | O_TRUNC, \
			S_IWRITE | S_IREAD);
		if (ft_strcmp("-f", (const char *)argv[1]) == 0 || \
		ft_strcmp("-s", (const char *)argv[1]) == 0)
			stack->onearg = 1;
		if (ft_strcmp("-f", (const char *)argv[2]) == 0 || \
		ft_strcmp("-s", (const char *)argv[2]) == 0)
			stack->twoarg = 1;
	}
}

void	parce_option(t_stack_m *stack, int argc, char **argv)
{
	if (ft_strcmp("-help", (const char *)argv[1]) == 0)
	{
		print_usage();
		exit(0);
	}
	if (argc == 2 && (ft_strcmp("-f", (const char *)argv[1]) == 0 ||\
	ft_strcmp("-s", (const char *)argv[1]) == 0))
	{
		print_usage();
		exit(0);
	}
	else if (argc == 3 && ((ft_strcmp("-f", (const char *)argv[1]) == 0 &&\
	ft_strcmp("-s", (const char *)argv[2]) == 0) || (ft_strcmp("-s",\
	(const char *)argv[1]) == 0 && ft_strcmp("-f",\
	(const char *)argv[2]) == 0)))
	{
		print_usage();
		exit(0);
	}
	else
		compare_option(argv, stack, argc);
}
