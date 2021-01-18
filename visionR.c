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

void setup2()
{
    turndirection = 0;
    walkdirection = 0;
    walkspeed = CUB / 6;
    turnspeed = 4 * (M_PI / 180);

}

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
	if (map[index_y][index_x] == '1')
        return (1);
    return(0);
}

void	vision()
{
	float xline;
	float yline;

	xline = xplayer;
	yline = yplayer;
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
		xplayer = newplayerx;
		yplayer = newplayery;
	}
}