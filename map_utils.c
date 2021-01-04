/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:40:21 by houbeid           #+#    #+#             */
/*   Updated: 2020/12/01 18:40:29 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void  ft_err(char *s)
{
	ft_putstr("Error\n");
	ft_putstr(s);
	exit(1);
}

int		is_empty(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '1' || s[i] == '2' || s[i] == '0' || s[i] == 'N' || s[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void  ft_check_zero(char **mat)
{
	int i;
	int j;

	i = 0;
	//ft_putstr("hamada");
	while(i < map_rows)
	{
		j = 0;
		while(j < map_clumns)
		{
			if(mat[i][j] == '0' || mat[i][j] == '2' || mat[i][j] == 'N')
			{
				if (mat[i][j] == 'N')
				{
					xplayer = j * CUB + (CUB / 2);
					yplayer = i * CUB + (CUB / 2);
					rotationangle = M_PI / 2;
				}
				if (i == map_rows - 1 || i == 0  || j == map_clumns - 1 || j  == 0)
					ft_err("map_error1");
				if (mat[i + 1][j] == ' ' || mat[i - 1][j] == ' ' || mat[i][j + 1] == ' ' || mat[i][j - 1] == ' ')
					ft_err("map_error2");
			}
			j++;
		}
		i++;
	}

}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	i = 0;
	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	while ((s1c[i] || s2c[i]))
	{
		if (s1c[i] != s2c[i])
			return (1);
		if (!*s2c && s1c)
			return (1);
		i++;
	}
	return (0);
}