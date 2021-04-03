/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:42:30 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/13 14:02:10 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy at most n symbols of the string src to dst
** if lenght of src < n the remainder of dst is filled with '\0'
** if lenght of src > n dst is not terminated
** src and dest should not overlap as the behavior is undefined
** IN: src and dst strings, numbers n of copied symbols
** OUT: *dst
*/

#include "libft.h"

static char	*ft_fill(char *dst, const char *src, unsigned int n)
{
	unsigned long i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned long	i;
	unsigned long	nb;

	i = 0;
	if (src == 0 || dst == 0)
		return (NULL);
	nb = ft_strlen(src);
	if (n <= nb)
		ft_fill(dst, src, n);
	else
	{
		ft_fill(dst, src, nb);
		while (i + 1 <= n - nb)
		{
			dst[i + nb] = '\0';
			i++;
		}
	}
	return (dst);
}
