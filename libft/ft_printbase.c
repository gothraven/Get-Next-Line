/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:28:32 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 02:28:46 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printbase(int nb, size_t base)
{
	char	*str;

	str = ft_itoa_base(nb, base);
	if (str)
		write(1, str, ft_strlen(str));
}
