/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:23:16 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 17:23:59 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** returns the next prime number greater or equal to the number nb
** IN: number
** OUT: next prime number
*/

#include "libft.h"

unsigned int	ft_find_next_prime(unsigned int nb)
{
	unsigned int	i;
	unsigned int	p;

	i = 0;
	p = 0;
	while (ft_is_prime(nb + i) != 1)
		i++;
	p = nb + i;
	return (p);
}
