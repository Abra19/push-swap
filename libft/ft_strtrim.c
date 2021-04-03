/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:22:42 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/12 14:23:51 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocates and returns a copy of the s without ’ ’, ’\n’ and ’\t’
** at the beginning or at the end of the string
** if s has no whitespaces at the beginning or at the end - returns a copy of s
** if the allocation fails the function returns NULL
** IN: string to be trimede
** OUT: trimmed string or a copy of s
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	if (s == 0)
		return (NULL);
	n = ft_strlen(s);
	while (i < n && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (n > 0 && (s[n - 1] == ' ' || s[n - 1] == '\n' || s[n - 1] == '\t'))
		n--;
	if (i != ft_strlen(s))
		n -= i;
	if (!(res = (char *)malloc((n + 1) * sizeof(*res))))
		return (NULL);
	else
	{
		while (i < ft_strlen(s) && j < n)
			res[j++] = s[i++];
		res[n] = '\0';
	}
	return (res);
}
