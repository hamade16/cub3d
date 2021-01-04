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

void setup()
{
    //xplayer = width / 2;
    //yplayer = height / 2;
    turndirection = 0;
    walkdirection = 0;
    // rotationangle = M_PI / 2; //PI / 2;
    walkspeed = CUB / 6;
    turnspeed = 4 * (M_PI / 180);
   // g_key.move_forward_or_backward = 0;
}
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
			if (x / CUB < ft_strlen(map[y / CUB]) && y / CUB < map_rows && map[y / CUB][x / CUB] != '1')
				pxl_ptr[x + y * (CUB * map_clumns)] = color;
			else
				t = 0;
			i += 0.1;
		}
		angle += (M_PI / 3) / (CUB * map_clumns);
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
			if (x / CUB < ft_strlen(map[y / CUB]) && y / CUB < map_rows && map[y / CUB][x / CUB] != '1')
				pxl_ptr[x + y * (CUB * map_clumns)] = color;
			else
				t = 0;
			i += 0.1;
		}
		angle += (M_PI / 3) / (CUB * map_clumns);
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
			if (x / CUB < ft_strlen(map[y / CUB]) && y / CUB < map_rows && map[y / CUB][x / CUB] != '1')
				pxl_ptr[x + y * (CUB * map_clumns)] = color;
			else
				t = 0;
			i += 0.1;
		}
		angle += (M_PI / 3) / (CUB * map_clumns);
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
			if (x / CUB < ft_strlen(map[y / CUB]) && y / CUB < map_rows && map[y / CUB][x / CUB] != '1')
				pxl_ptr[x + y * (CUB * map_clumns)] = color;
			else
				t = 0;
			i += 0.1;
		}
		angle += (M_PI / 3) / (CUB * map_clumns);
	}
}*/

int	haswallat(float x, float y)
{
	int		index_x;
	int		index_y;

	//index_x = x;
	//index_y = y;
	if (x <= 0 || x > map_clumns * CUB || y <= 0 || y > map_rows * CUB)
		return (1);
	index_x = (int)floor(x / CUB);
	index_y = (int)floor(y / CUB);
	//printf("index x%d\n",index_x);
		//printf("index %d\n",index_y);

	if (map[index_y][index_x] == '1')
        return (1);
    return(0);
	// return (map[index_y][index_x]);
    // return (map[index_y][index_x] != 0);
}

void	vision()
{
	float xline;
	float yline;

	xline = xplayer;
	yline = yplayer;
	//rotationangle = normalized_angle(rotationangle);
	rotationangle += turndirection * turnspeed;
	rotationangle = normalized_angle(rotationangle);
	movestep = walkdirection * walkspeed;
	if (walkdirection == 1 || walkdirection == -1)
	{
		newplayerx = xplayer + cos(rotationangle) * movestep;
		newplayery = yplayer + sin(rotationangle) * movestep;
	}
	if (!haswallat(newplayerx, newplayery))
	{
	//	printf("%f\n",rotationangle);
		xplayer = newplayerx;
		yplayer = newplayery;
	}
	/*
	rayangle = rotationangle - fov / 2;
	//rayangle = normalisedangle(rayangle);
	 while (rayangle < rotationangle + fov / 2)
	 {
		// printf("%d/n", num_rays);
		i = 0;
	 	while(1)
	 	{
	 		xline = xplayer + cos(rayangle) * i;
	 		yline = yplayer + sin(rayangle) * i; 
	 		//printf("%f\n",rotationangle);
			if (map[(int)yline / CUB][(int)xline / CUB] == '1')
				break;
			// printf("  %c \n", map[(int)yline / CUB][(int)xline / CUB]);
	 		my_mlx_pixel_put(xline, yline, 0xffb703, img_ptr);
			i += 0.1;
	 	}
	 	rayangle += fov / num_rays;
	 }*/
}
/*
void	H_intersection(int color)
{
	float i;
	float j;

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
	rayangle = rotationangle - fov / 2;
	rayangle = normaliseangle(rayangle);
	israyfacingdown = 0;
	israyfacingup = 0;
	israyfacingleft = 0;
	israyfacingright = 0;
	yintercept = floor(yplayer / CUB) * CUB;
	xintercept = xplayer + (yintercept - yplayer) / tan(rayangle);
	if (rayangle > 0 && rayangle < M_PI)
		israyfacingdown = rayangle;
	else
		israyfacingup = rayangle;
	if (rayangle <  0.5 * M_PI && rayangle > 1.5 * M_PI)
		israyfacingright = rayangle;
	else
		israyfacingleft = rayangle;
	if (israyfacingdown != 0)
		yintercept += CUB;
	ystep = CUB;
	if (israyfacingdown == 0)
		ystep *= -1;
	xstep = CUB / tan(rayangle);
	if (israyfacingright == 0 && xstep > 0)
		xstep *= -1;
	if (israyfacingright != 0 && xstep < 0)
		xstep *= -1;
	nexthorzx = xintercept;
	nexthorzy = yintercept;
	if (israyfacingdown == 0)
		nexthorzy--;
	while (nexthorzx >= 0 && nexthorzx <= width && nexthorzy >= 0 && nexthorzy <= height)
	{
		if (haswallat(nexthorzx, nexthorzy) == '1')
		{
			wallhitx = nexthorzx;
			wallhity = nexthorzy;
			for (j = 0; j < 1 ; j++)
			{
				i = xplayer;
				while (i <= wallhitx)
				{
					xline = xplayer + cos(rayangle) * i;
					yline = yplayer + sin(rayangle) * i; 
					//printf("%f\n",rotationangle);
					pxl_ptr[xline + yline * (CUB * map_clumns)] = color;
					i += 0.1;
				}
				//rayangle += fov / num_rays;
			}
			break;
		}
		else 
		{
			nexthorzx += xstep;
			nexthorzy += ystep;
		}
	}
}*/