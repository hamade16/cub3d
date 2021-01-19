/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:58:22 by houbeid           #+#    #+#             */
/*   Updated: 2019/11/21 23:00:57 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char*)s + ft_strlen((char*)s));
	while (*s && *s != c)
		s++;
	if (*s == '\0')
		return (0);
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		len1;
	int		len2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(s3 = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s3[len1 + i] = s2[i];
		i++;
	}
	s3[i + len1] = '\0';
	return (s3);
}
