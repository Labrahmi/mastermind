/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:21:20 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/10/19 16:20:07 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	if (!lst)
		return (0);
	temp = lst;
	i = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
