/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:16:38 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/13 18:54:03 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *backup, char *buffer)
{
	char		*temp;
	int			i;
	int			j;

	temp = (char *) malloc(ft_strlen(backup) + ft_strlen(buffer) + 1);
	if (!(temp))
		return (0);
	i = -1;
	j = 0;
	while (backup[++i])
		temp[i] = backup[i];
	while (buffer[j])
		temp[i++] = buffer[j++];
	temp[i] = '\0';
	return (temp);
}
