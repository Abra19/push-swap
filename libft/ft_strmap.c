/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:27:57 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/12 15:28:33 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** applies f to each character of the string s
** create new string for result of the successive applications of f
** IN: string s, function to apply to each character of s
** OUT: string created from the successive applications of f
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	char			*res;
	unsigned long	len;
	unsigned long	i;

	i = 0;
	if (s != 0 && f != 0)
	{
		str = (char*)s;
		len = ft_strlen(s);
		res = (char*)malloc(sizeof(*str) * (len + 1));
		if (res == 0)
			return (NULL);
		ft_bzero(res, (len + 1));
		while (str[i] != '\0')
		{
			res[i] = f(str[i]);
			i++;
		}
		return (res);
	}
	return (NULL);
}
