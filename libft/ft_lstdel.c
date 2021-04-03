/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:17:04 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 16:18:29 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes as a parameter the adress of a pointer and frees the
** memory of this link’s and every successors of that link
** using the function del given as a parameter
** pointer to the link that was just freed must be set to NULL
** IN: the adress of a ponter to the first link of a list that need to be fried
** OUT: void
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;
	t_list	*tmp;

	list = *alst;
	while (list != 0)
	{
		tmp = list;
		ft_lstdelone(&list, del);
		list = tmp->next;
	}
	*alst = NULL;
}
