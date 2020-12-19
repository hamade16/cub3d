/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:45:16 by houbeid           #+#    #+#             */
/*   Updated: 2019/11/10 02:51:08 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		ft_count_split(char const *str, char c)
{
	int count;
	int j;

	count = 0;
	j = 0;
	while (*str != '\0')
	{
		if (*str == c)
			j = 0;
		else if (j == 0)
		{
			j = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static	int		ft_wsp(char const *str, int i, char c)
{
	int len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static	void	*free_t(char **split, int j)
{
	while (j--)
		free(split[j]);
	free(split);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	int		k;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (!(split = (char**)malloc(sizeof(char*) * (ft_count_split(s, c) + 2))))
		return (NULL);
	while (j < ft_count_split(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(split[j] = (char*)malloc(sizeof(char) * (ft_wsp(s, i, c) + 1))))
			return (free_t(split, j));
		k = 0;
		while (s[i] != c && s[i] != '\0')
			split[j][k++] = s[i++];
		split[j][k] = '\0';
		j++;
	}
	split[j] = NULL;
	return (split);
}
