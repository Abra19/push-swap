/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:25:19 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/09 16:59:32 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copies n bytes from src to dst
** if dst and src overlap behavior is undefined
** returns the original value of dst
** IN: strings dst, src; numbers of copied bytes n
** OUT: *dst
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst1;
	unsigned char		*src1;
	unsigned long		i;

	i = 0;
	if (dst == src)
		return (dst);
	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
