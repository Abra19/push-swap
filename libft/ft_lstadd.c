/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:20:34 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 16:21:01 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** adds the element new at the beginning of the list
** IN: adress of a pointer to the first link of a list
** IN: link to add at the beginning of the list
** OUT: new link
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
