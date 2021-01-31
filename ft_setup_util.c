/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 08:42:52 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/01/10 08:43:11 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_resps(char *str, char c, short o)
{
	int		i;

	i = 0;
	c = (o) ? c : 27;
	while (str[i] != c && o)
		i++;
	while (str[i] == c && o)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			str[i] = (o) ? 27 : ' ';
		i++;
	}
	return (str);
}

char	*clearspc(char *str)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (str[++i] != '\0')
	{
		if (str[i] != ' ')
			str[++j] = str[i];
		if (str[i] == ' ' && ft_isdigit(str[i - 1]))
			throwerror("RGB params must be followed by comma!");
	}
	str[++j] = '\0';
	return (str);
}