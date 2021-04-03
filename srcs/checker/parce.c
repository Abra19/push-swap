/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:23:42 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		fill_stack_a(int i, char **argv, int argc, t_stack_m *stack)
{
	int		j;

	j = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > INTSIZE)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		if (ft_atol(argv[i]) > INT32_MAX ||
		ft_atol(argv[i]) < INT32_MIN || ft_strcmp("+", argv[i]) == 0 ||\
		ft_strcmp("-", argv[i]) == 0)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		stack->stack_a.arr[j] = ft_atoi(argv[i]);
		j++;
		i++;
	}
	return (1);
}

int		fill_stack_a_str(char **num_arr, int height, t_stack_m *stack)
{
	int		j;

	j = 0;
	while (num_arr[j] != 0)
	{
		if (ft_strlen(num_arr[j]) > INTSIZE)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		if (ft_atol(num_arr[j]) > INT32_MAX ||
		ft_atol(num_arr[j]) < INT32_MIN || ft_strcmp("+", num_arr[j]) == 0\
		|| ft_strcmp("-", num_arr[j]) == 0)
		{
			clean_up_map((void **)num_arr, height + 1);
			ft_putendl_fd("Error", 2);
			return (0);
		}
		stack->stack_a.arr[j] = ft_atoi(num_arr[j]);
		j++;
	}
	return (1);
}

int		parse_arg_num(int i, int argc, char **argv)
{
	int		count;

	count = 0;
	while (i < argc)
	{
		if (ft_isnum(argv[i]) == 0)
		{
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		count++;
		i++;
	}
	return (count);
}

int		parce_string_arg_num(char **num_arr, int height)
{
	int		j;

	j = 0;
	while (num_arr[j] != 0)
	{
		if (ft_isnum(num_arr[j]) == 0)
		{
			clean_up_map((void **)num_arr, height + 1);
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		j++;
	}
	return (j);
}

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
