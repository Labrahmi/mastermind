/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:27:45 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/12/07 09:57:48 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printvar(char c, va_list app)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(app, int));
	else if (c == 'd' || c == 'i')
		ft_print_int_(va_arg(app, int), &count);
	else if (c == 'u')
		ft_print_uint(va_arg(app, unsigned int), &count);
	else if (c == 's')
		count += ft_print_str_(va_arg(app, char *));
	else if (c == 'x' || c == 'X')
		ft_print_hexl(va_arg(app, unsigned int), &count, c);
	else if (c == 'p')
	{
		count += ft_print_str_("0x");
		ft_print_hexp(va_arg(app, unsigned long), &count);
	}
	else if (c == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *ch, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, ch);
	while (ch[i] != '\0')
	{
		if (ch[i] != '%')
			count += ft_print_char(ch[i]);
		else
		{
			i++;
			count += ft_printvar(ch[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}
