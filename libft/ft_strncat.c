/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:45:44 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/13 14:01:40 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** n symbols of s1 to the end of s2 then add'\0'
** s1 and s2 should not overlap as the behavior is undefined
** IN: strings s1 and s2, number of symbols n
** OUT: *s1
*/

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	unsigned long i;
	unsigned long j;

	i = 0;
	j = 0;
	if (s1 == 0 && s2 == 0)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (j < n && s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
