/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:23:33 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 16:24:36 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** iterate the list lst and applyes f to each link
** IN: adress of a pointer to the first link of a list
** IN: adress of a function to apply to each link of a list
** OUT: void
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != 0)
	{
		f(tmp);
		tmp = tmp->next;
	}
}
