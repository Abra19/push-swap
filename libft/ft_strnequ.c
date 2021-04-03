/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:49:06 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/12 15:24:14 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** lexicographical comparison between s1 and s2 up to n characters
** or until a ’\0’
** if the 2 strings are identical the function returns 1, or 0 otherwise
** IN: string s1, s2, n - maximum number of characters to be compared
** OUT: 1 or 0 according to if the 2 strings are identical or not
*/

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, int n)
{
	int		i;

	i = 0;
	if (s1 == 0 && s2 == 0)
		return (1);
	else if ((s1 != 0 && s2 == 0) || (s1 == 0 && s2 != 0))
		return (0);
	if (n > ft_strlen(s1))
	{
		if (ft_strequ(s1, s2) == 1)
			return (1);
	}
	else
	{
		while (s1[i] != '\0' && s2[i] != '\0' && i < n)
		{
			if (s1[i] == s2[i])
				i++;
			else
				break ;
		}
		if (i == n)
			return (1);
	}
	return (0);
}
