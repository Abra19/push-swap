/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:07:14 by dlaure            #+#    #+#             */
/*   Updated: 2019/10/02 21:24:57 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns a line read from a file descriptor
** “line” - characters that end with ’\n’ or with End Of File
** calling in a loop will allow to read the text on a file descriptor
** one line at a time until the end of the text
** reads from a file, from the standard output, from a redirection
** IN: file descriptor that will be used to read
** IN: address of a pointer to a character that will be used
**     to save the line read from the file descriptor
** OUT: 1 - a line read, 0 - reading completing (EOF)
** OUT: -1 - an error has happened
** OUT: without ’\n’
*/

static int	read_file_buf_char(const int fd, char *buff, char **str, char c)
{
	int		rez;
	char	*tmp;

	while ((rez = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rez] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], c))
			break ;
	}
	return (rez);
}

static void	line_by_line_char(char **str, const int fd, char c, char **line)
{
	int		i;
	char	*swap;

	i = 0;
	while (str[fd][i] != c && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == c)
	{
		*line = ft_strsub(str[fd], 0, i);
		swap = ft_strdup(&(str[fd][i + 1]));
		free(str[fd]);
		str[fd] = swap;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[FD_NUM];
	int			rez;
	char		*buff;

	if (fd < 0 || line == NULL || fd > FD_NUM)
		return (-1);
	buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (buff == 0)
		return (-1);
	rez = read_file_buf_char(fd, buff, str, '\n');
	free(buff);
	if (rez < 0)
		return (-1);
	else if (rez == 0 && str[fd] == NULL)
		return (0);
	else
		line_by_line_char(str, fd, '\n', line);
	return (1);
}
