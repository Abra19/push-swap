/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:29:13 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/12 20:42:28 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** outputs the string s to the file descriptor fd
** IN: string s to output, file descriptor fd
** OUT: void
*/

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s != 0)
	{
		if (fd >= 0)
			while (*s != '\0' && s != 0)
			{
				ft_putchar_fd(*s, fd);
				s++;
			}
	}
}
