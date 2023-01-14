/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:06:49 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/10/23 01:09:14 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	l;

	l = ft_strlen(needle);
	if (l == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp((haystack + i), needle, l) == 0)
			{
				if ((i + l) <= len)
				{
					return ((char *)haystack + i);
				}
			}
		}
		i++;
	}
	return (NULL);
}
