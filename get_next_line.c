/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:59:14 by abelarif          #+#    #+#             */
/*   Updated: 2020/02/08 18:56:33 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(char *buf, char **rest)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	if (*rest)
	{
		free(*rest);
		*rest = NULL;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_checkvalue(int read_value, char **line, char *rest, char *buf)
{
	static int i = 0;

	if (read_value < 0)
	{
		free_all(buf, &rest);
		return (-1);
	}
	else if (read_value == 0 && i == 0)
	{
		*line = rest;
		i++;
		free_all(buf, &rest);
		return (0);
	}
	else if (read_value == 0 && i > 0)
		*line = strdup("");
	free(buf);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			read_value;
	static char	*rest;
	int			index_nl;
	char		*buf;

	index_nl = -1;
	if (fd < 0 || BUFFER_SIZE < 0 || !line || !(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	((rest == NULL) ? (rest = malloc(1)) : (rest));
	while (1)
	{
		if ((index_nl = check_nl(rest)) >= 0)
		{
			*line = r_l(rest, index_nl);
			free(buf);
			return ((!(*line) || !(rest = r_r(rest, index_nl))) ? -1 : 1);
		}
		if (index_nl < 0)
		{
			if ((read_value = read(fd, buf, BUFFER_SIZE)) <= 0)
				return (ft_checkvalue(read_value, line, rest, buf));
			buf[read_value] = '\0';
			rest = strjoin(&rest, buf);
		}
	}
}
