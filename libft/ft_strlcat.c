/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:59:40 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/13 14:07:00 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** apend dstsize - ft_strlen(dts) - 1 symbols of src to the end of dst
** then add'\0'
** dst and src should not overlap as the behavior is undefined
** IN: strings dst and src, max lenght of finish string - dstsize
** OUT: lenght of src + dstsize if dstsize = 0 or ft_strlen(dst) > dstsize
** OUT: lenght of src + lenght of dst if dstsize >= ftstrlen(dst)e
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned long i;
	unsigned long j;
	unsigned long lsrc;
	unsigned long res;

	i = 0;
	j = 0;
	if (src == 0 && dst == 0)
		return (0);
	lsrc = ft_strlen(src);
	while (dst[i] != '\0')
		i++;
	res = i;
	if (dstsize == 0 || res >= dstsize)
		return (lsrc + dstsize);
	while (src[j] != '\0' && res + j < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res + lsrc);
}
