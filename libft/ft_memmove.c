/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:15:27 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/10/21 10:33:39 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*char_dst;
	char	*char_src;
	size_t	i;

	char_dst = (char *)dst;
	char_src = (char *)src;
	if ((char_dst == NULL) && (char_src == NULL))
		return (NULL);
	i = 0;
	if (dst <= src)
		ft_memcpy(char_dst, char_src, len);
	else
	{
		while (len > i)
		{
			char_dst[len - 1] = char_src[len - 1];
			len--;
		}
	}
	return (dst);
}
