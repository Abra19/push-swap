/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:00:06 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 17:17:31 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** returns 1 if nb is a prime number and 0 if it isn’t
** IN: number
** OUT: 1 - is true, 0 - is false
*/

int		ft_is_prime(unsigned long long nb)
{
	unsigned long long	i;
	int					mod;

	i = 2;
	mod = 0;
	if (nb == 0 || nb == 1 || nb == 4)
		return (0);
	if (nb == 3 || nb == 2 || nb == 5)
		return (1);
	while (i < (nb / 2))
	{
		mod = nb % i;
		if (mod != 0)
			i++;
		else
			break ;
	}
	if (mod == 0)
		i = 0;
	else
		i = 1;
	return (i);
}
