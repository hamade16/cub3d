/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 04:35:39 by houbeid           #+#    #+#             */
/*   Updated: 2019/11/08 06:24:48 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	i = 0;
	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while ((s1c[i] || s2c[i]) && i < n)
	{
		if (s1c[i] != s2c[i])
			return (s1c[i] - s2c[i]);
		if (!*s1c)
			break ;
		i++;
	}
	return (0);
}
