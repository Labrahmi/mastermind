/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:18:17 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/12/07 09:55:07 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*set_line(char *backup)
{
	char	*line;
	int		i;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	i += 1 * (backup[i] == '\n');
	line = (char *)malloc((i + 1));
	if (!(line))
		return (0);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*set_strnig(char *backup)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (backup[i] && (backup[i] != '\n'))
		i++;
	if (backup[i] == '\n')
		i++;
	if (!(backup[i]))
	{
		free(backup);
		return (0);
	}
	temp = (char *)malloc(ft_strlen(backup) - i + 1);
	if (!temp)
		return (0);
	j = 0;
	while (backup[i])
		temp[j++] = backup[i++];
	temp[j] = '\0';
	free(backup);
	return (temp);
}

char	*ft_reader(int fd, char *backup)
{
	char	buffer[BUFFER_SIZE + 1];
	int		b;

	buffer[0] = '\0';
	b = 1;
	while (b && !(ft_strchr(backup, '\n')))
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b < 0)
		{
			free(backup);
			backup = (NULL);
			return (0);
		}
		buffer[b] = '\0';
		if (!(backup))
			backup = ft_strdup(buffer);
		else
			backup = ft_strjoin(backup, buffer);
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	backup = ft_reader(fd, backup);
	if (!(backup))
	{
		free(backup);
		backup = (NULL);
		return (0);
	}
	line = set_line(backup);
	backup = set_strnig(backup);
	if (!(line[0]))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
