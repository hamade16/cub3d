/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 00:12:08 by houbeid           #+#    #+#             */
/*   Updated: 2019/11/25 20:24:02 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_m(char *str, int c)
{
	free(str);
	return (c);
}

int		res_ex(char **line, char **res, char *ptr)
{
	char *p;

	*ptr = '\0';
	*line = ft_strdup(*res);
	p = *res;
	*res = ft_strdup(++ptr);
	return (free_m(p, 1));
}

int		get_next_line1(int fd, char *buff, char **line, char **res)
{
	int		i;
	int		k;
	char	*ptr;
	char	*p;

	k = 1;
	while (k && (i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
		{
			*ptr = '\0';
			p = *res;
			*res = ft_strdup(++ptr);
			free(p);
			k = 0;
		}
		p = *line;
		*line = ft_strjoin(*line, buff);
		free(p);
	}
	return (i);
}

int		retourne(int i, char **res)
{
	if (i > 0)
		return (1);
	else if (i == 0)
	{
		free(*res);
		*res = NULL;
		return (0);
	}
	else
		return (-1);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	char		*buff;
	char		*ptr;
	static char	*res;

	if (read(fd, NULL, 0) || BUFFER_SIZE < 0 || line == NULL)
		return (-1);
	if (res)
	{
		if ((ptr = ft_strchr(res, '\n')))
		{
			return (res_ex(line, &res, ptr));
		}
		else
			*line = ft_strdup(res);
	}
	else
		*line = ft_strdup("");
	if (!(buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	i = get_next_line1(fd, buff, line, &res);
	free(buff);
	return (retourne(i, &res));
}
