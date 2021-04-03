/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:01:59 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 15:13:22 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate and returns a “fresh” string ending with ’\0’
** representing the integer n given as argument
** negative numbers must be supported
** if the allocation fails the function returns NULL
** IN: integer to be transformed into a string
** OUT: string representing the integer passed as argument
*/

#include "libft.h"

static int	ft_size_int_to_char(int n)
{
	int				i;
	unsigned int	nb;
	int				size;

	i = 0;
	nb = n;
	if (n < 0)
	{
		nb = (unsigned int)n * -1;
		i++;
	}
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i++;
	}
	size = i + 1;
	return (size);
}

char		*ft_itoa(int n)
{
	char			*res;
	unsigned int	nb;
	int				size;

	size = ft_size_int_to_char(n);
	res = (char*)malloc(sizeof(*res) * (size + 1));
	if (res == 0)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		nb = (unsigned int)n * -1;
	}
	else
		nb = (unsigned int)n;
	res[size] = '\0';
	size--;
	while (nb > 9)
	{
		res[size--] = (nb % 10 + '0');
		nb = nb / 10;
	}
	res[size] = nb % 10 + '0';
	return (res);
}
