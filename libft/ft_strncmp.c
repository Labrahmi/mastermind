/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:01:47 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/10/17 01:45:23 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	uc1 = (unsigned char *) s1;
	uc2 = (unsigned char *) s2;
	i = 0;
	while (i < n && (uc1[i] || uc2[i]))
	{
		if (uc1[i] != uc2[i])
			return (uc1[i] - uc2[i]);
		i++;
	}
	return (0);
}
