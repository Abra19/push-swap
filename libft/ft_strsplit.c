/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:34:31 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/20 15:00:36 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocates and returns an array of “fresh” strings
** obtained by spliting s using the character c as a delimiter
** if the allocation fails the function returns NULLe
** IN: string to split? delimiter character c
** OUT: the array of strings - result of spliting
*/

#include "libft.h"

static int	ft_find_char(char const *s, char c, int *i)
{
	int		j;
	int		k;

	j = *i;
	while (s[j] == c)
		j++;
	k = j;
	*i = j;
	return (k);
}

static int	ft_nb_words(const char *str, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		nb = nb + 1;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	if (str[i - 1] == c)
		nb = nb - 1;
	return (nb);
}

static char	*ft_write_word(const char *str, int i, int nb)
{
	int		k;
	char	*word;

	k = 0;
	word = (char*)malloc(sizeof(char) * ((i - nb) + 1));
	if (word == 0)
		return (NULL);
	while (nb < i)
	{
		word[k] = str[nb];
		nb++;
		k++;
	}
	word[k] = '\0';
	return (word);
}

static void	ft_free_mem(char const *s, int i, int k, char **array)
{
	int		j;

	j = 0;
	while (j <= i)
	{
		free(ft_write_word(s, j, k));
		j++;
	}
	free(array);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**array;

	i = 0;
	j = 0;
	if (s == 0)
		return (NULL);
	if (!(array = (char**)malloc(sizeof(char*) * (ft_nb_words(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0' && j < ft_nb_words(s, c))
	{
		k = ft_find_char(s, c, &i);
		while (s[i] != c && s[i] != '\0')
			i++;
		if ((array[j++] = ft_write_word(s, i, k)) == 0)
			ft_free_mem(s, i, k, array);
	}
	array[ft_nb_words(s, c)] = 0;
	return (array);
}
