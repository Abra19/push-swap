/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:00:02 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:11:53 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** converts the initial portion of *str to int representation
** IN: string str
** OUT: int nb
*/

static int	ft_overflow(int count, char c)
{
	if (count > 20)
	{
		if (c == '-')
			return (0);
		else
			return (-1);
	}
	return (1);
}

static int	ft_splitparam(const char *str, int i, int *p)
{
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == ' '\
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		*p = i;
		i++;
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	long long int	nb;
	int				i;
	int				p;
	int				count;
	const long int	max_at = 9223372036854775807;

	nb = 0;
	i = 0;
	p = 0;
	i = ft_splitparam(str, i, &p);
	count = i;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		nb = 10 * nb + (str[i++] - '0');
	count = i - count;
	if (ft_overflow(count, str[p]) == 0)
		return (0);
	else if (ft_overflow(count, str[p]) == -1)
		return (-1);
	if (str[p] == '-' && (nb - max_at - 1) >= 0)
		return (0);
	else if (nb - max_at > 0)
		return (-1);
	if (str[p] == '-' && nb - max_at - 1 <= 0)
		return (-nb);
	return (nb);
}
