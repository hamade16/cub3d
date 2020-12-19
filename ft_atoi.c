/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:13:16 by houbeid           #+#    #+#             */
/*   Updated: 2019/11/08 21:43:43 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	result(int i, const char *str, int sign)
{
	unsigned long num;

	num = 0;
	while (*(str + i) && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (num > 9223372036854775807)
		return ((sign > 0) ? (-1) : (0));
	return (num * sign);
}

int	ft_atoi(const char *str)
{
	int				sign;
	int				i;

	sign = 1;
	i = 0;
	while (*(str + i) && (str[i] == ' ' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\t' || str[i] == '\f' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] == '+' || str[i] == '-')
		return (0);
	return (result(i, str, sign));
}
