/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:19:24 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/09 19:20:29 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return 0 if c is not printable character and 1 othrwise
** IN: int c
** OUT: true (1) or false (0)
*/

int		ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
