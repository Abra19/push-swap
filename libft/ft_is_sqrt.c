/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sqrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:55:54 by dlaure            #+#    #+#             */
/*   Updated: 2019/10/24 15:05:53 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** returns the square root of int number if sqrt is rational
** returns 0 if the square root is an irrational number
** if nb = 0 sqrt = 0
** IN: number nb
** OUT: 0 or sqrt(nb)
*/

unsigned long	ft_is_sqrt(unsigned long nb)
{
	unsigned long	tmp;
	unsigned long	res;

	tmp = 0;
	res = 0;
	while (nb >= (tmp * tmp))
	{
		res = tmp;
		tmp++;
		if (nb != (res * res))
			res = 0;
	}
	return (res);
}
