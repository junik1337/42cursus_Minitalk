/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:41:59 by ayassir           #+#    #+#             */
/*   Updated: 2022/01/18 19:27:02 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexx(unsigned long i)
{
	char	*hexx;
	int		rt;

	rt = 0;
	hexx = "0123456789ABCDEF";
	if (i >= 0 && i <= 15)
	{
		i = hexx[i];
		rt += write(1, &i, 1);
	}
	else
	{
		rt += ft_puthexx(i / 16);
		rt += ft_puthexx(i % 16);
	}
	return (rt);
}
