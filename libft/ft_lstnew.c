/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:55:40 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/11 22:31:46 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocates and returns a “fresh” link
** content and content_size are initialized
** if the parameter content is nul the variable content is initialized to NULL
** and the variable content_size is initialized to 0 even
** if the parameter content_size isn’t
** the variable next is initialized to NULL
** if the allocation fails the function returns NULL
** IN: content to put in the new link
** IN: size of the content of the new link
** OUT: new link
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)ft_memalloc(sizeof(t_list));
	if (new == 0)
		return (NULL);
	if (content == 0)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = malloc(content_size);
		if (new->content == NULL)
			return (NULL);
		ft_memmove(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
