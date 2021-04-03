/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:19:42 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 19:36:16 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** writes n bytes of value c to the string str
** IN: string str, value to paste c, numbers of bytes n
** OUT: *str
*/

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char*)str;
	if (n != 0)
	{
		while (i < n)
		{
			ptr[i] = c;
			i++;
		}
	}
	return (str);
}
