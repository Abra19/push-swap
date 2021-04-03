/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:53:56 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 19:44:37 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** compares byte string s1 against byte string s2
** both strings is n bytes long
** returns 0 if the two strings are identical
** if *s1 != *s2 returns the difference between the first two differing bytes
** zero-length strings are always identical
** IN: strings s1, s2; lenght of the strings n
** OUT: *s1 = *s2 -> 0
 ** OUT: *s1 != *s2 -> difference between the first non identical
*/

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s1_k;
	const unsigned char		*s2_k;
	unsigned long			i;

	i = 0;
	s1_k = (const unsigned char*)s1;
	s2_k = (const unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1_k[i] != s2_k[i])
			return ((int)(s1_k[i] - s2_k[i]));
		i++;
	}
	return (0);
}
