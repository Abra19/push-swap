/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:21:13 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/13 14:02:39 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locates the last occurrence of c in the string pointed by str
** if c is '\0' function locate the terminating '\0'
** IN: string str, symbol c
** OUT: pointer to c or NULL if c does not appear in the string
*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	sym;
	char	*c_find;

	c_find = 0;
	sym = (char)c;
	if (str == 0)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == sym)
			c_find = (char *)str;
		str++;
	}
	if (c_find != 0)
		return (c_find);
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
