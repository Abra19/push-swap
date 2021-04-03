/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:44:20 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/12 15:22:01 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** lexicographical comparison between s1 and s2
** if the 2 strings are identical the function returns 1, or 0 otherwise
** IN: string s1, s2
** OUT: 1 or 0 according to if the 2 strings are identical or not
*/

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (s1 == 0 && s2 == 0)
		return (1);
	else if ((s1 != 0 && s2 == 0) || (s1 == 0 && s2 != 0))
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	if (i == ft_strlen(s1))
		return (1);
	return (0);
}
