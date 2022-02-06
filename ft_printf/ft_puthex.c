/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:44:30 by ayassir           #+#    #+#             */
/*   Updated: 2022/01/17 15:04:25 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long i)
{
	char	*hex;
	int		rt;

	rt = 0;
	hex = "0123456789abcdef";
	if (i >= 0 && i <= 15)
	{
		i = hex[i];
		rt += write(1, &i, 1);
	}
	else
	{
		rt += ft_puthex(i / 16);
		rt += ft_puthex(i % 16);
	}
	return (rt);
}
