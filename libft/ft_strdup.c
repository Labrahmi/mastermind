/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:12:51 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/13 18:53:52 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*ret_pointer;
	int		len;
	int		i;

	len = ft_strlen(s1);
	ret_pointer = (char *) ft_calloc((len + 1), sizeof(char));
	if (!ret_pointer)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret_pointer[i] = s1[i];
	return (ret_pointer);
}
