/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:18:59 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/12/07 09:42:23 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s)
	{
		if (ft_strlen(s) == 0 && c == '\0')
			return ((char *) s);
		while (s[i] != '\0')
		{
			if (s[i] == (char) c)
			{
				return ((char *) s + i);
			}
			i++;
			if ((s[i] == '\0') && (c == '\0'))
				return ((char *) s + i);
		}
	}
	return (0);
}
