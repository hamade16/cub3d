/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <houbeid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 21:43:09 by houbeid           #+#    #+#             */
/*   Updated: 2021/02/03 23:20:09 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void fetch_sp(char *str)
{
    int i;
    void *tmp;
	
    i = 2;
    tmp = mlx_xpm_file_to_image(mlx_ptr, str, &i, &i);

	if (tmp == NULL)
    	throwerror("ERROR\n Invalid South texture file");
    sp_file = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
    //t_data.no_completed = 1;
}

void		count_sprite(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < map_rows)
	{
		j = 0;
		while (j < map_clumns)
		{
			if (map[i][j] == '2')
			{
				g_sprt[g_nbr_sprite].x = (j + 0.5) * CUB;
				g_sprt[g_nbr_sprite].y = (i + 0.5) * CUB;
				g_sprt[g_nbr_sprite].distance =
				distancebetweenpoints(g_sprt[g_nbr_sprite].x,
				 g_sprt[g_nbr_sprite].y, xplayer,yplayer);
				g_nbr_sprite++;
			}
			j++;
		}
		i++;
	}
}

int			sprite_utils(int i, int *k, int r, int j)
{
	if (r)
	{
		if (g_sprt[i].it_x + *k >= 0 && (g_sprt[i].it_x + *k) < width
		&& (g_sprt[i].it_y + j >= 0) && (g_sprt[i].it_y + j < height))
			return (1);
		else
			return (0);
	}
	else
	{
		if ((g_sprt[i].it_x + *k < 0 || g_sprt[i].it_x + *k > width)
		|| (g_sprt[i].distance >= rays[(int)g_sprt[i].it_x + *k].distance &&
		rays[(int)g_sprt[i].it_x + *k].distance != 0))
		{
			*k += 1;
			return (1);
		}
		else
			return (0);
	}
}

void		draw_sprite(int i)
{
	int		j;
	int		k;
	int		color;

	j = 0;
	color = 0;
	while (j < (int)g_sprt[i].size)
	{
		k = 0;
		while (k < (int)g_sprt[i].size)
		{
			if (sprite_utils(i, &k, 0, j))
				continue;
			if ((int)(64 * (j * 64 / (int)g_sprt[i].size) +
			(k * 64 / (int)g_sprt[i].size)) < (64 * 64))
				color = sp_file[(int)(64 *
				(j * 64 / (int)g_sprt[i].size) +
				(k * 64 / (int)g_sprt[i].size))];
			if (sprite_utils(i, &k, 1, j) && color > 0)
                my_mlx_pixel_put((g_sprt[i].it_x + k), (g_sprt[i].it_y + j), color, img_ptr);
			k++;
		}
		j++;
	}
}

void		sort_sprite(void)
{
	int			i;
	int			j;
	t_sprt	sprite_swap;

	i = 0;
	while (i < g_nbr_sprite - 1)
	{
		j = i + 1;
		while (j < g_nbr_sprite)
		{
			if (g_sprt[i].distance < g_sprt[j].distance)
			{
				sprite_swap = g_sprt[i];
				g_sprt[i] = g_sprt[j];
				g_sprt[j] = sprite_swap;
			}
			j++;
		}
		i++;
	}
}

void		calcul_sprite(void)
{
	int		i;

	i = 0;
	count_sprite();
	while (i < g_nbr_sprite)
	{
		g_sprt[i].angle = atan2(g_sprt[i].y -
		yplayer, g_sprt[i].x - xplayer);
		while (g_sprt[i].angle - rotationangle > M_PI)
			g_sprt[i].angle -= 2 * M_PI;
		while (g_sprt[i].angle - rotationangle < -M_PI)
			g_sprt[i].angle += 2 * M_PI;
		g_sprt[i].size = (width / g_sprt[i].distance) * CUB;
		g_sprt[i].it_x = (g_sprt[i].angle - rotationangle)
		/ (M_PI / 3) * width + (width / 2 - g_sprt[i].size / 2);
		g_sprt[i].it_y = height / 2 - g_sprt[i].size / 2;
		i++;
	}
	sort_sprite();
	i = 0;
	while (i < g_nbr_sprite)
		draw_sprite(i++);
}