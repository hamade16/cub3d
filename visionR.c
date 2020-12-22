/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visionR.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 05:43:00 by houbeid           #+#    #+#             */
/*   Updated: 2020/12/10 05:43:07 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	vision_N(int color)
{
	int x;
	int y;
	double angle;
	int	t  = 1;
	double i  = 0;

	angle = (1.5 * M_PI) - M_PI / 6;
	while(angle < (1.5 * M_PI) + M_PI / 6)
	{
		i = 0;
		t = 1;
		while (t)
		{
			x = cos(angle) * i + xplayer;
			y = sin(angle) * i + yplayer;
			if (x / cub < ft_strlen(map[y / cub]) && y / cub < map_rows && map[y / cub][x / cub] != '1')
				pxl_ptr[x + y * (cub * map_clumns)] = color;
			else
				t = 0;
			i += 0.1;
		}
		angle += (M_PI / 3) / (cub * map_clumns);
	}
}

void	vision_S(int color)
{
	int x;
	int y;
	double angle;
	int	t  = 1;
	double i  = 0;

	angle = (2 * M_PI) - M_PI / 6;
	while(angle < (2 * M_PI) + M_PI / 6)
	{
		i = 0;
		t = 1;
		while (t)
		{
			x = cos(angle) * i + xplayer;
			y = sin(angle) * i + yplayer;
			if (x / cub < ft_strlen(map[y / cub]) && y / cub < map_rows && map[y / cub][x / cub] != '1')
				pxl_ptr[x + y * (cub * map_clumns)] = color;
			else
				t = 0;
			i += 0.1;
		}
		angle += (M_PI / 3) / (cub * map_clumns);
	}
}

void	vision_W(int color)
{
	int x;
	int y;
	double angle;
	int	t  = 1;
	double i  = 0;

	angle = (0.5 * M_PI) - M_PI / 6;
	while(angle < (0.5 * M_PI) + M_PI / 6)
	{
		i = 0;
		t = 1;
		while (t)
		{
			x = cos(angle) * i + xplayer;
			y = sin(angle) * i + yplayer;
			if (x / cub < ft_strlen(map[y / cub]) && y / cub < map_rows && map[y / cub][x / cub] != '1')
				pxl_ptr[x + y * (cub * map_clumns)] = color;
			else
				t = 0;
			i += 0.1;
		}
		angle += (M_PI / 3) / (cub * map_clumns);
	}
}

void	vision_E(int color)
{
	int x;
	int y;
	double angle;
	int	t  = 1;
	double i  = 0;

	angle = (M_PI) - M_PI / 6;
	while(angle < (M_PI) + M_PI / 6)
	{
		i = 0;
		t = 1;
		while (t)
		{
			x = cos(angle) * i + xplayer;
			y = sin(angle) * i + yplayer;
			if (x / cub < ft_strlen(map[y / cub]) && y / cub < map_rows && map[y / cub][x / cub] != '1')
				pxl_ptr[x + y * (cub * map_clumns)] = color;
			else
				t = 0;
			i += 0.1;
		}
		angle += (M_PI / 3) / (cub * map_clumns);
	}
}*/
char	haswallat(xplayer, yplayer)
{
	int x;
	int y;

	x = newplayerx / cub;
	y = newplayery / cub;
	return (map[y][x]);
}

void	vision(int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	xline = xplayer;
	yline = yplayer;
	rotationangle += turndirection * 2 * (M_PI / 180);
	movestep = walkdirection * 2;
	newplayerx = xplayer + cos(rotationangle) * movestep;
	newplayery = yplayer + sin(rotationangle) * movestep;
	if (haswallat(newplayerx, newplayery) != '1')
	{
		xplayer = newplayerx;
		yplayer = newplayery;
	}
	/*if (walkdirection == -1 || walkdirection == 1)
	{
		xplayer += cos(rotationangle) * movestep;
		yplayer += sin(rotationangle) * movestep;
	}*/
	/*if (compt == 1)
	{
		xplayer = xplayer + cos(rotationangle) * 5;
		yplayer = yplayer + sin(rotationangle) * 5; 
	}
	if (compt == 2)
	{
		xplayer = xplayer - cos(rotationangle) * 5;
		yplayer = yplayer - sin(rotationangle) * 5; 
	}*/
		//printf("%f\n",rotationangle);
	rayangle = rotationangle - fov / 2;
	for (j = 0; j < num_rays; j++)
	{
		for (i = 0; i < 20; i++)
		{
			xline = xplayer + cos(rayangle) * i;
			yline = yplayer + sin(rayangle) * i; 
			//printf("%f\n",rotationangle);
			pxl_ptr[xline + yline * (cub * map_clumns)] = color;
		}
		rayangle += fov / num_rays;
	}
}