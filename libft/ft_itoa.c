/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:43:28 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/10/21 11:07:44 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(long long int number)
{
	int	i;

	i = 0;
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

static int	ft_isnegative(long long int *number)
{
	if (*number < 0)
	{
		*number *= (-1);
		return (1);
	}
	return (0);
}

char	*ft_zero(void)
{
	char	*zero;

	zero = (char *) ft_calloc(2, sizeof(char));
	zero[0] = '0';
	return (zero);
}

char	*ft_itoa(int num)
{
	char			*string;
	int				is_negative;
	int				i;
	long long int	n;

	if (num == 0)
		return (ft_zero());
	n = num;
	is_negative = ft_isnegative(&n);
	i = ft_int_len(n) + (1 * (is_negative));
	string = (char *)malloc((i + 1) * sizeof(char));
	if (!string)
		return (NULL);
	string[i] = '\0';
	i--;
	while (n > 0)
	{
		string[i] = (char)(n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (is_negative)
		string[i] = '-';
	return (string);
}
