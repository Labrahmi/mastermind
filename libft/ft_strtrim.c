/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:21:08 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/10/21 12:31:17 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_end(char const *s1, char const *set)
{
	int	times;
	int	len;
	int	i;

	len = ft_strlen(s1) - 1;
	times = 0;
	i = 0;
	while ((len > 0) && (i != -1))
	{
		while (set[i] != '\0')
		{
			if (set[i] == s1[len])
				times++;
			i++;
		}
		if (times == 0)
			i = (-1);
		else
		{
			times = 0;
			i = 0;
			len--;
		}
	}
	return (len);
}

static int	find_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	times;

	i = 0;
	j = 0;
	times = 0;
	while ((s1[i] != '\0') && (j != (-1)))
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				times++;
			j++;
		}
		if (times == 0)
			j = (-1);
		else
		{
			j = 0;
			times = 0;
			i++;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if ((!s1) || (!set))
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set);
	return (ft_substr(s1, start, ((end - start) + 1)));
}
