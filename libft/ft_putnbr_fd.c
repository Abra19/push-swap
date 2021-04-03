/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:35:26 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 15:43:15 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** outputs the integer n to the file descriptor fd
** IN: integer to print, file descriptor fd
** OUT: void
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nbr;

	if (fd >= 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			nbr = (unsigned int)n * -1;
		}
		else
			nbr = (unsigned int)n;
		if (nbr > 9)
			ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
}
