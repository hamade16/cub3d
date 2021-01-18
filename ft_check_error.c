/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:54:03 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/01/10 11:17:07 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		validfile(char *file, char *ext)
{
	char	**spfile;
	int		i;
	int		len;

	spfile = ft_split(file, '.');
	len = 0;
	i = -1;
	while (spfile[len])
		len++;
	if (len >= 2)
	{
		while (spfile[len - 1][++i])
			spfile[len - 1][i] = ft_tolower(spfile[len - 1][i]);
		if (ft_strncmp(spfile[len - 1], ext, 4) == 0)
			return (retfreetwo(spfile, 1));
	}
	return (retfreetwo(spfile,
	throwerror(ft_strjoin("Your extention must be : ", ext))));
}

int		throwerror(char *error)
{
	error = ft_strjoin("\n\033[1;31m(x) Error\n >> \033[0;31m", error);
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	free(error);
	return (on_exit());
}
/*
void	defaultsets(void)
{
	t_map.colf = -1;
	t_map.colc = -1;
	t_win.resl.width = 0;
	t_win.resl.height = 0;
}
*/