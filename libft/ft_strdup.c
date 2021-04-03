/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:48:55 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/13 14:00:29 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocates sufficient memory for a copy of the string src and does the copy
** returns a pointer to maked copy
** if insufficient memory is available return  NULL
** IN: string src
** OUT: pointer to string-copy dest
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char			*dest;
	unsigned long	l;
	unsigned long	i;

	i = 0;
	if (src == 0)
		return (NULL);
	l = ft_strlen(src);
	dest = (char*)malloc(sizeof(*dest) * (l + 1));
	if (dest == NULL)
		return (NULL);
	while (i < l)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
