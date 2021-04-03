/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power_of_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:29:48 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 17:36:00 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** define is n is power of 2
** IN: number n
** OUT: 1 - n is power of 2 and 0 - if not
*/

int		is_power_of_2(unsigned long long n)
{
	int		m;

	if (n == 1 || n == 2)
		return (1);
	if (n == 0)
		return (0);
	if (n > 2)
	{
		while (n != 2)
		{
			n = n / 2;
			m = n % 2;
			if (m == 1)
			{
				return (0);
				break ;
			}
		}
		return (1);
	}
	return (0);
}
