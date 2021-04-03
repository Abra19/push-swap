/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 02:00:50 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isnum(char *str)
{
	int		i;

	if (str[0] == '-' || str[0] == '+')
		i = 1;
	else
		i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		count_height(char **str)
{
	int		height;

	height = 0;
	while (str[height] != 0)
		height++;
	return (height);
}

int		ft_abs(int a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}

void	ft_swap_int(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		max_two_int(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
