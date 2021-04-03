/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_options_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/22 20:24:36 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	option_usage(char **argv, int argc)
{
	if (ft_strcmp("-help", (const char *)argv[1]) == 0)
		usage_with_exit();
	if (argc == 2 && (ft_strcmp("-f", (const char *)argv[1]) == 0 ||\
	ft_strcmp("-s", (const char *)argv[1]) == 0 || ft_strcmp("-v",\
	(const char *)argv[1]) == 0 || ft_strcmp("-c", (const char *)argv[1]) == 0\
	|| ft_strcmp("-m", (const char *)argv[1]) == 0))
		usage_with_exit();
	if (argc >= 3 && (ft_strcmp("-c", (const char *)argv[1]) == 0 ||\
	(ft_strcmp("-c", (const char *)argv[2]) == 0 && ft_strcmp("-v",\
	(const char *)argv[1]) != 0) || (ft_strcmp("-m",\
	(const char *)argv[1]) == 0 && (ft_strcmp("-c", (const char *)argv[2]) == 0\
	|| ft_strcmp("-s", (const char *)argv[2]) == 0)) || ft_strcmp("-m",\
	(const char *)argv[2]) == 0 || ft_strcmp("-v", (const char *)argv[2]) == 0))
		usage_with_exit();
}

void	parse_opt_1_2(char **argv, t_stack_m *stack)
{
	parce_options_ch_2(argv[1], argv[2], stack);
	parce_options_ch_1(argv[1], stack);
}

void	parse_opt_1_3(char **argv, t_stack_m *stack)
{
	parce_option_ch_3(argv[1], argv[2], argv[3], stack);
	parce_options_ch_2(argv[1], argv[2], stack);
	parce_options_ch_1(argv[1], stack);
}

void	parse_opt_all(char **argv, t_stack_m *stack)
{
	parce_options_ch(argv, stack);
	parce_option_ch_3(argv[1], argv[2], argv[3], stack);
	parce_options_ch_2(argv[1], argv[2], stack);
	parce_options_ch_1(argv[1], stack);
}

void	work_with_options(t_stack_m *stack, char **argv, int argc)
{
	option_usage(argv, argc);
	if (argc == 3 && (ft_strcmp("-f", (const char *)argv[2]) != 0 &&\
	ft_strcmp("-s", (const char *)argv[2]) != 0 && ft_strcmp("-v",\
	(const char *)argv[2]) != 0 && ft_strcmp("-c", (const char *)argv[2]) != 0\
	&& ft_strcmp("-m", (const char *)argv[2]) != 0))
		parce_options_ch_1(argv[1], stack);
	else if (argc == 4 && (ft_strcmp("-f", (const char *)argv[3]) != 0 &&\
	ft_strcmp("-s", (const char *)argv[3]) != 0 && ft_strcmp("-v",\
	(const char *)argv[3]) != 0 && ft_strcmp("-c", (const char *)argv[3]) != 0\
	&& ft_strcmp("-m", (const char *)argv[3]) != 0))
		parse_opt_1_2(argv, stack);
	else if (argc == 5 && (ft_strcmp("-f", (const char *)argv[4]) != 0 &&\
	ft_strcmp("-s", (const char *)argv[4]) != 0 && ft_strcmp("-v",\
	(const char *)argv[4]) != 0 && ft_strcmp("-c", (const char *)argv[4]) != 0\
	&& ft_strcmp("-m", (const char *)argv[4]) != 0))
		parse_opt_1_3(argv, stack);
	else if (argc == 5 && (ft_strcmp("-f", (const char *)argv[4]) == 0 ||\
	ft_strcmp("-s", (const char *)argv[4]) == 0 || ft_strcmp("-v",\
	(const char *)argv[4]) == 0 || ft_strcmp("-c", (const char *)argv[4]) == 0\
	|| ft_strcmp("-m", (const char *)argv[4]) == 0))
		usage_with_exit();
	else if (argc > 5)
		parse_opt_all(argv, stack);
}
