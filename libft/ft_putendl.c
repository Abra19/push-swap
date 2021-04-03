/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:20:52 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/12 20:41:40 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** outputs the string s to the standard output followed by a '\n'
** IN: string s to output
** OUT: void
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s != 0)
	{
		while (*s != '\0')
		{
			ft_putchar(*s);
			s++;
		}
		ft_putchar('\n');
	}
}
