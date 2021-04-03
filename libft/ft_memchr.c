/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:49:53 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/09 16:57:50 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locates the first occurrence of c in string str
** returns a pointer to the byte located or NULL if "c" absent in n bytes
** IN: string *tr, symbols to find char c, numbers of bytes n (if "c" absent)
** OUT: pointer to c or NULL
*/

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char		*str_k;
	unsigned char		sym;
	unsigned long		i;

	i = 0;
	str_k = (unsigned char*)str;
	sym = (unsigned char)c;
	while (i < n)
	{
		if (str_k[i] == sym)
			return ((void *)(str_k + i));
		i++;
	}
	return (NULL);
}
