/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:44:52 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/09 17:26:47 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copies n bytes from string src to string dst
** strings may overlap
** IN: strings str, dst, numbers of copied bytes - n
** OUT: *dest
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned long	i;

	i = 0;
	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	if (dst1 > src1)
		while (i++ < n)
			dst1[n - i] = src1[n - i];
	else
		while (i < n)
		{
			if (dst1 != src1)
				dst1[i] = src1[i];
			i++;
		}
	return (dst);
}
