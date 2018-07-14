/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:16:40 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 00:45:23 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tnext;

	if (alst != NULL)
	{
		tmp = *alst;
		while (tmp != NULL)
		{
			if (tmp->next != NULL)
			{
				tnext = tmp->next;
				ft_lstdelone(&tmp, del);
				tmp = tnext;
			}
			else
			{
				ft_lstdelone(&tmp, del);
			}
		}
		*alst = NULL;
	}
}
