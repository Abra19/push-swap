/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:30:56 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/09 18:34:44 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locates the first occurrence of string fnd in the string pointed by str
** IN: string str, string fnd
** OUT: if fnd is empty - return str
** OUT: if fnd not occurs in src - return NULL
** OUT: in other case - pointer to the first character of first occurence fnd
*/

#include "libft.h"

char	*ft_strstr(const char *str, const char *fnd)
{
	int		i;
	int		j;

	i = 0;
	if (*fnd == 0)
		return ((char *)str);
	while (str[i] != '\0')
	{
		if (str[i] == fnd[0])
		{
			j = 1;
			while (fnd[j] != '\0' && str[i + j] == fnd[j])
				j++;
			if (fnd[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
