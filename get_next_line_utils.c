/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:22:16 by abelarif          #+#    #+#             */
/*   Updated: 2020/01/24 20:22:16 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_nl(const char *rest)
{
	int i;

	i = 0;
	while (rest[i])
	{
		if (rest[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*strjoin(char *rest, char *buf)
{
	int		lenrest;
	int		lenbuf;
	char	*p;
	int		i;
	int		j;

	if (rest == 0)
		return (buf);
	lenbuf = ft_strlen(buf);
	lenrest = ft_strlen(rest);
	if (!(p = malloc((lenrest + lenbuf + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (++i < lenrest)
		p[i] = rest[i];
	j = 0;
	while (i < (lenrest + lenbuf))
		p[i++] = buf[j++];
	p[i] = '\0';
	return (p);
}

char	*r_r(char *rest, int index_nl)
{
	char	*r;
	int		i;

	i = 0;
	if (!(r = malloc(sizeof(char) * (ft_strlen(rest) - index_nl))))
		return (0);
	while ((index_nl + 1) < (int)ft_strlen(rest))
	{
		r[i] = rest[index_nl + 1];
		i++;
		index_nl++;
	}
	r[i] = '\0';
	return (r);
}

char	*r_l(char *rest, int index_nl)
{
	char	*l;
	int		i;

	i = 0;
	if (!(l = malloc(sizeof(char) * (index_nl + 1))))
		return (0);
	while (i < index_nl)
	{
		l[i] = rest[i];
		i++;
	}
	l[i] = '\0';
	return (l);
}