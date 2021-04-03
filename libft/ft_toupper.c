/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:24:52 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/11 18:43:28 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** converts a lower-case letter to the corresponding upper-case letter
** IN: int c
** OUT:  if c is a lower-case letter returns the corresponding upper-case letter
** OUT: otherwise, the argument is returned unchanged
*/

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
