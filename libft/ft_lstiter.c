/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 01:04:59 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 01:13:27 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*tnext;

	if (lst != NULL)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			tnext = tmp->next;
			f(tmp);
			tmp = tnext;
		}
	}
}
