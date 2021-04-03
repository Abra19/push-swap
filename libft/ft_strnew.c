/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:49:46 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/11 21:21:44 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocates and returns a “fresh” string ending with '\0'
** each character of the string is initialized at ’\0’
** if the allocation fails, the function returns NULL
** IN: size of the string to be allocated
** OUT: string allocated and initialized to 0
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*res;

	if (size == 9223372036854775807)
		return (NULL);
	res = (char *)malloc((size + 1) * sizeof(*res));
	if (res == 0)
		return (NULL);
	ft_bzero(res, size + 1);
	return (res);
}
