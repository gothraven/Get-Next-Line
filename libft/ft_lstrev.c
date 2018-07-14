/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:52:18 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 02:52:20 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstrev_rec(t_list *l, t_list *prev, t_list *next)
{
	l->next = prev;
	prev = l;
	if (next)
	{
		l = next;
		return (ft_lstrev_rec(l, prev, l->next));
	}
	return (l);
}

t_list			*ft_lstrev(t_list *l)
{
	if (!l)
		return (0x0);
	if (l->next)
		return (ft_lstrev_rec(l, NULL, l->next));
	return (l);
}
