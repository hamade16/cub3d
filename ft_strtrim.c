/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:24:01 by houbeid           #+#    #+#             */
/*   Updated: 2019/10/24 17:53:18 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen((char*)s1);
	while ((ft_strchr(set, s1[i]) != 0) && s1[i])
		i++;
	while ((len - 1) > i && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	s2 = (char*)malloc(sizeof(char) * (len - i + 1));
	if (!s2)
		return (NULL);
	while (i < len)
		s2[j++] = s1[i++];
	s2[j] = '\0';
	return (s2);
}
