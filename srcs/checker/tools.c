/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/24 16:53:21 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int		ft_intlen(int nbr, uint8_t base)
{
	int		size;
	int		tmp;

	tmp = ft_abs(nbr);
	size = 0;
	if (tmp == 0)
		return (1);
	while (tmp > 0)
	{
		tmp = tmp / base;
		size++;
	}
	return (size);
}

int		min_two_int(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
