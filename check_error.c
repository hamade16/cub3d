/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:23:50 by houbeid           #+#    #+#             */
/*   Updated: 2020/12/04 22:24:00 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}


int    check_identfierR(char *l)
{
    char **s;
    int i;
	int j;

    i = 0;
	j = 0;
    if (ft_strchr2(l, 'R') == 1)
	{
		//ft_putstr(&l[0]);
		if (l[0] != 'R')
			ft_err("error2");
		s = ft_split(l, ' ');
		//printf("%s", s[1]);
		if (ft_strcmp(s[0], "R") != 0)
			ft_err("error3");
		while(s[i])
			i++;
		if (i != 3)
			ft_err("error4");
		i = 0;
		while (s[++i][j])
		{
			while (s[i][++j])
			{
				if(ft_isdigit(s[i][j]) == 0)
					ft_err("error5");
			}
		}
		width = ft_atoi(s[1]);
		height = ft_atoi(s[2]);
        return (1);
	}
	else
    	return (0);
}