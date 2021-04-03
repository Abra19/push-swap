/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:22:31 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 22:49:41 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** applies f to each character of the string passed as argument
** passing its index as first argument
** each character is passed by address to f to be modified if necessary
** IN: string s, function to apply to each character of s and its index
** OUT: void
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned long	i;

	i = 0;
	if (s != 0 && f != 0)
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
}
