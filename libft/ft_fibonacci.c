/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:49:47 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 17:11:53 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** returns the n-th element of the Fibonacci sequence
** max n = 93
** the Fibonacci sequence starts like this: 0, 1, 1
** the first element being at the 0 index
** IN: index of element of the Fibonacci sequence
 ** OUT: the value of element with index n of the Fibonacci sequence
*/

#include "libft.h"

unsigned long long	ft_fibonacci(int n)
{
	int					i;
	unsigned long long	res;

	i = 3;
	res = 0;
	if (n > 93)
		write(2, "Max index of the elementh in function = 93\n", 43);
	if (n == 0 || n > 93)
		return (0);
	if (n == 1 || n == 2)
		res = 1;
	while (i <= n)
	{
		res = ft_fibonacci(i - 1) + ft_fibonacci(i - 2);
		i++;
	}
	return (res);
}
