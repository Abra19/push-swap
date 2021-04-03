/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:05:06 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 16:05:41 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes as a parameter a link’s pointer address and frees the
** memory of the link’s content using the function del
** frees the link’s memory
** memory of next must not be freed under any circumstance
** pointer to the link that was just freed must be set to NULL
** IN: adress of a pointer to a link that need to be fried
** OUT: void
*/

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
