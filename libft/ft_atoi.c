/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:39:48 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/10/09 15:26:57 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	helper(const char *str, long long some, int i, int sign)
{
	while (ft_isdigit(str[i]))
	{
		some = (some * 10) + (str[i] - '0');
		i++;
		if (some < 0)
		{
			if (sign != -1)
				return (-1);
			else
				return (0);
		}
	}
	return (some);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	some;

	i = 0;
	sign = 1;
	some = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (helper(str, some, i, sign) * sign);
}
