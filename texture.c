/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:29:50 by houbeid           #+#    #+#             */
/*   Updated: 2021/01/31 17:30:01 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void fetch_no(char *str)
{
    int i;
    void *tmp;
	
    i = 2;
    tmp = mlx_xpm_file_to_image(mlx_ptr, str, &i, &i);
	if (tmp == NULL)
    	throwerror("ERROR\n Invalid North texture file");
    g_texture.north_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
    //t_data.no_completed = 1;
}

void fetch_so(char *str)
{
    int i;
    void *tmp;
	
    i = 2;
    tmp = mlx_xpm_file_to_image(mlx_ptr, str, &i, &i);

	if (tmp == NULL)
    	throwerror("ERROR\n Invalid South texture file");
    g_texture.south_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
    //t_data.no_completed = 1;
}

void fetch_ea(char *str)
{
	printf("%s\n",str);
    int i;
    void *tmp;
	
    i = 2;
    tmp = mlx_xpm_file_to_image(mlx_ptr, str, &i, &i);
	if (tmp == NULL)
    	throwerror("ERROR\n Invalid East texture file");
    g_texture.east_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
    //t_data.no_completed = 1;
}

void fetch_we(char *str)
{
	printf("%s\n",str);
    int i;
    void *tmp;
	
    i = 2;
    tmp = mlx_xpm_file_to_image(mlx_ptr, str, &i, &i);
	if (tmp == NULL)
    	throwerror("ERROR\n Invalid West texture file");
    g_texture.west_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
    //t_data.no_completed = 1;
}