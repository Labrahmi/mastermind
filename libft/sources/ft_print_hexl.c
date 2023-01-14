/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:58:04 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/12/07 09:59:31 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_hexl(unsigned int ul, int *ip, char c)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (ul < 16)
	{
		*ip += ft_print_char(hex[ul]);
	}
	else
	{
		ft_print_hexl(ul / 16, ip, c);
		ft_print_hexl(ul % 16, ip, c);
	}
}
