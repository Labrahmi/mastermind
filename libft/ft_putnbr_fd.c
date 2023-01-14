/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:36:00 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/10/17 15:58:43 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	long long int	lli;

	lli = n;
	if (lli < 0)
	{
		lli = lli * (-1);
		write(fd, "-", 1);
	}
	if (lli < 10)
	{
		c = (lli % 10) + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(lli / 10, fd);
		ft_putnbr_fd(lli % 10, fd);
	}
}
