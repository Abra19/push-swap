/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:27:20 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/14 19:12:38 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** iterate the list lst and applyes f to each link
** create a "fresh" list result of the successive application of f
** if the allocation fails f returns 0
** IN: adress of a pointer to the first link of a list
** IN: adress of a function to apply to each link of a list
** OUT: new list
*/

#include "libft.h"

static void	ft_clean_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst != 0)
	{
		tmp = lst->next;
		ft_memdel((void*)&lst);
		lst = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*prev;

	if (lst == NULL)
		return (NULL);
	first = f(lst);
	prev = first;
	while (lst->next != NULL)
	{
		lst = lst->next;
		prev->next = f(lst);
		if ((prev->next) == 0)
		{
			ft_clean_lst(first);
			return (NULL);
		}
		prev = prev->next;
	}
	return (first);
}
