/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:38:01 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/09 17:02:31 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copies bytes from string src to string dst
** if c occurs in the string src, the copy stops and a pointer to the byte
** after the copy of c in dst is returned
** if c does not occurs n bytes are copied and a NULL pointer is returned
** src and dst should not overlap as the behavior is undefined
** IN: strings dst, str; symbols stop copy char c;
** IN: numbers of bytes n - if "c" absent
** OUT: pointer to "c" or NULL (if "c" absent)
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_k;
	unsigned char		*src_k;
	unsigned char		sym;
	unsigned long		i;

	i = 0;
	src_k = (unsigned char*)src;
	dst_k = (unsigned char*)dst;
	sym = (unsigned char)c;
	while (i < n)
	{
		dst_k[i] = src_k[i];
		if (src_k[i] == sym)
			return ((void *)(dst_k + i + 1));
		i++;
	}
	return (NULL);
}
