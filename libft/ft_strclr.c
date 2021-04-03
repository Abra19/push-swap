/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:58:18 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/12 15:33:29 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sets every character of the string to the value '\0'
** IN: string that needs to be cleared
** OUT: void
*/

void	ft_strclr(char *s)
{
	char	*str;

	if (s != 0)
	{
		str = s;
		while (*str != '\0' && str != 0)
		{
			*str = '\0';
			str++;
		}
	}
}
