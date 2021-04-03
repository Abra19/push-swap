/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:39:41 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/09 18:42:13 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locates the first occurrence of string fnd in the string pointed by str
** area of search in src is restricted by n symbols
** characters that appear after a '\0' character are not searched
** IN: string str, string fnd, number of symbols for search
** OUT: if fnd is empty - return src
** OUT: if fnd not occurs in n symbols of src - return NULL
** OUT: in other case - pointer to the first character of first occurence fnd
*/

#include "libft.h"

char	*ft_strnstr(const char *str, const char *fnd, size_t n)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	if (*fnd == 0)
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == fnd[0])
		{
			j = 1;
			while (fnd[j] != '\0' && str[i + j] == fnd[j] && (i + j) < n)
				j++;
			if (fnd[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
