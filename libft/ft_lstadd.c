/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:57:31 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 01:03:42 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *lstnew)
{
	if (alst != NULL)
	{
		if (*alst != NULL)
		{
			lstnew->next = *alst;
		}
		*alst = lstnew;
	}
}
