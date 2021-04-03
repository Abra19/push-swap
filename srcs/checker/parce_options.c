/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/22 20:24:36 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parce_options_ch_1(char *str, t_stack_m *stack)
{
	if (ft_strcmp("-f", (const char *)str) == 0 || ft_strcmp("-s",\
	(const char *)str) == 0 || ft_strcmp("-v", (const char *)str) == 0 ||\
	ft_strcmp("-c", (const char *)str) == 0 ||\
	ft_strcmp("-m", (const char *)str) == 0)
	{
		if (ft_strcmp("-f", (const char *)str) == 0)
			stack->fd = open("./test.c", O_RDWR);
		else if (ft_strcmp("-v", (const char *)str) == 0)
			stack->debag = 1;
		else if (ft_strcmp("-m", (const char *)str) == 0)
			stack->draw = 1;
		else if (ft_strcmp("-c", (const char *)str) == 0)
			usage_with_exit();
		if (ft_strcmp("-v", (const char *)str) == 0 || ft_strcmp("-m",\
		(const char *)str) == 0 || ft_strcmp("-f", (const char *)str) == 0\
		|| ft_strcmp("-s", (const char *)str) == 0)
			stack->onearg = 1;
	}
}

void	parce_options_ch_2(char *str1, char *str2, t_stack_m *stack)
{
	if (ft_strcmp("-f", (const char *)str2) == 0 || ft_strcmp("-s",\
	(const char *)str2) == 0 || ft_strcmp("-v", (const char *)str2) == 0 ||\
	ft_strcmp("-c", (const char *)str2) == 0 ||\
	ft_strcmp("-m", (const char *)str2) == 0)
	{
		if (ft_strcmp((const char *)str1, (const char *)str2) == 0)
			usage_with_exit();
		if (ft_strcmp("-f", (const char *)str2) == 0)
			stack->fd = open("./test.c", O_RDWR);
		else if (ft_strcmp("-c", (const char *)str2) == 0)
			stack->color = 1;
		else if (ft_strcmp("-v", (const char *)str2) == 0 || \
		ft_strcmp("-m", (const char *)str2) == 0)
			usage_with_exit();
		if (ft_strcmp("-f", (const char *)str2) == 0 || ft_strcmp("-s",\
		(const char *)str2) == 0 || ft_strcmp("-c", (const char *)str2) == 0)
			stack->twoarg = 1;
	}
}

void	parce_option_ch_3(char *str1, char *str2, char *str3, t_stack_m *stack)
{
	if (ft_strcmp("-f", (const char *)str3) == 0 || ft_strcmp("-s",\
	(const char *)str3) == 0 || ft_strcmp("-v", (const char *)str3) == 0 ||\
	ft_strcmp("-c", (const char *)str3) == 0 ||\
	ft_strcmp("-m", (const char *)str3) == 0)
	{
		if (ft_strcmp((const char *)str1, (const char *)str3) == 0 ||\
		ft_strcmp((const char *)str2, (const char *)str3) == 0)
			usage_with_exit();
		if (ft_strcmp("-f", (const char *)str3) == 0)
			stack->fd = open("./test.c", O_RDWR);
		else if (ft_strcmp("-v", (const char *)str3) == 0 || ft_strcmp("-m",\
		(const char *)str3) == 0 || ft_strcmp("-c", (const char *)str3) == 0\
		|| (ft_strcmp("-m", (const char *)str1) == 0 &&\
		ft_strcmp("-s", (const char *)str3) == 0))
			usage_with_exit();
		if (ft_strcmp("-f", (const char *)str3) == 0 || \
		ft_strcmp("-s", (const char *)str3) == 0)
			stack->threearg = 1;
	}
}

void	parce_options_ch(char **argv, t_stack_m *stack)
{
	if (ft_strcmp("-f", (const char *)argv[4]) == 0 || ft_strcmp("-s",\
	(const char *)argv[4]) == 0 || ft_strcmp("-v", (const char *)argv[4]) == 0\
	|| ft_strcmp("-c", (const char *)argv[4]) == 0 ||\
	ft_strcmp("-m", (const char *)argv[4]) == 0)
	{
		if (ft_strcmp((const char *)argv[1], (const char *)argv[4]) == 0 || \
		ft_strcmp((const char *)argv[2], (const char *)argv[4]) == 0 || \
		ft_strcmp((const char *)argv[3], (const char *)argv[4]) == 0)
			usage_with_exit();
	}
	if (ft_strcmp("-m", (const char *)argv[4]) == 0 || ft_strcmp("-v",\
	(const char *)argv[4]) == 0 || ft_strcmp("-c", (const char *)argv[4]) == 0)
		usage_with_exit();
	if (ft_strcmp("-f", (const char *)argv[4]) == 0)
		stack->fd = open("./test.c", O_RDWR);
	if (ft_strcmp("-f", (const char *)argv[4]) == 0 || \
	ft_strcmp("-s", (const char *)argv[4]) == 0)
		stack->fourarg = 1;
}
