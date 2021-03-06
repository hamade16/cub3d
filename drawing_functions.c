/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:25:30 by houbeid           #+#    #+#             */
/*   Updated: 2020/12/24 15:25:35 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void    draw_line(float x_one,float y_one,float x_zero,float y_zero)
{
    float dx;
    float dy;
    float steps;
    float x_inc;
    float y_inc;
    float i;
    i = 0;
    dx = x_one - x_zero;
    dy = y_one - y_zero;

    if (fabsf(dx) > fabsf(dy))
        steps = fabsf(dx);
    else 
        steps = fabsf(dy);
    x_inc = dx / steps;
    y_inc = dy / steps;
    while (i < steps)
    {        
        my_mlx_pixel_put(x_zero * 0.2,y_zero * 0.2,0x0000FF,img_ptr);
        x_zero += x_inc;
        y_zero  += y_inc;
        //printf("%f\n",y);
        //printf("%f\n",x);
        i++;
    }
    
    
}
void            my_mlx_pixel_put(int x,int y, int color, void *img)
{
    int     me;
	int *tmp;
    if (x < 0 || x >= width || y < 0 || y >= height)
		return ;
    tmp = (int*)mlx_get_data_addr(img, &me, &me, &me);
    tmp[x + (y * width)] = color;
}