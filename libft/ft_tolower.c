/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:29:36 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/11 18:44:13 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** converts a upper-case letter to the corresponding lower-case
** IN: int c
** OUT:  if c is a upper-case letter returns the corresponding lower-case letter
** OUT: otherwise, the argument is returned unchanged
*/

int		ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
