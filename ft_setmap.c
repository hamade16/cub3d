/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 08:40:08 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/01/10 08:40:41 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player(char dir, float x, float y)
{
	if (!t_player.dir)
	{
		t_player.dir = dir;
		yplayer = (y * CUB) + (CUB / 2);
		xplayer = (x * CUB) + (CUB / 2);
		if (dir == 'N')
			rotationangle = 270;
		else if (dir == 'S')
			rotationangle = 90;
		else if (dir == 'W')
			rotationangle = 180;
		else if (dir == 'E')
			rotationangle = 0;
	}
	else
	{
		map = NULL;
		throwerror("You must define one player only !");
	}
}

int			checkmap(int lenx, int leny)
{
	int x;
	int y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if ((x > 0 && y > 0 && x < lenx && y < leny)
			&& checkforin(map[y][x], "0234WESN")
			&& (map[y + 1][x] == ' ' || map[y][x + 1] == ' ' ||
			map[y - 1][x] == ' ' || map[y][x - 1] == ' '))
				return (throwerror("Map Invalid"));
			if (checkforin(map[y][x], "WESN"))
				set_player(map[y][x], x, y);
			if (map[y][x] == '2' || map[y][x] == '3')
				set_sprite(x, y);
		}
	}
	return (1);
}

static int	addlinemap(int index, char *line, int lenx, int leny)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < lenx)
	{
		if (checkforin(line[j], "0234WESN")
		&& (index == 0 || index == (leny - 1)
		|| i == 0 || i == (lenx - 1)))
			return (throwerror("Map must be closed"));
		if (line[j])
		{
			map[index][i] = line[j];
			j++;
		}
		else
			map[index][i] = ' ';
		if (!checkforin(map[index][i], " 01234WESN"))
			return (throwerror("Character invalid in map"));
		i++;
	}
	map[index][lenx] = '\0';
	return (1);
}

static int	mapsets(char *cubfile, int lenx, int leny)
{
	char	*line;
	int		nr;
	int		index;
	int		fd;
	int		i;

	map = malloc((leny + 1) * sizeof(char*));
	map[leny] = 0;
	nr = -1;
	while (++nr < leny)
		map[nr] = malloc((lenx + 1) * sizeof(char));
	if ((fd = open(cubfile, O_RDONLY)) < 0)
		return (-1);
	index = 0;
	while (((nr = get_next_line(fd, &line)) >= 0) && index < leny)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			nr = addlinemap(index++, line, lenx, leny);
		if (retfree(NULL, line, nr) <= 0)
			break ;
	}
	return ((retfree(NULL, line, nr) >= 0) ? checkmap(lenx, leny) : -1);
}

int			set_map(char *cubfile, int fd, char *line)
{
	int nr;
	int i;

	nr = 0;
	map_rows = 1;
	map_clumns = ft_strlen(line);
	while ((nr = get_next_line(fd, &line)) >= 0)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			nr = ft_strlen(line);
			map_clumns = (map_clumns < nr) ? nr : map_clumns;
			map_rows++;
		}
		else
			nr = (nr == 0 && !line[i]) ? 0
				: throwerror("MAP must be in file End & have '1' around it.");
		if (retfree(line, NULL, nr) == 0)
			break ;
	}
	return ((nr == 0)
		? mapsets(cubfile, map_clumns, map_rows) : -1);
}
