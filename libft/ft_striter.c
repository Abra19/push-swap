/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:12:00 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/09 20:21:07 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** applies f to each character of the string passed as argument
** each character is passed by address to f to be modified if necessary
** IN: string s, function to apply to each character of s
** OUT: void
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s != 0 && f != 0)
		while (*s != '\0')
		{
			f(s);
			s++;
		}
}
