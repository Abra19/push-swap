/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:26:38 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 15:27:06 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** outputs the character c to the file descriptor fd
** IN: character to output, file descriptor fd
** OUT: void
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}
