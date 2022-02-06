/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:21:32 by ayassir           #+#    #+#             */
/*   Updated: 2022/01/18 19:26:14 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *str)
{
	int					rt;
	unsigned long		i;

	rt = 0;
	i = (unsigned long) str;
	rt += ft_putstr("0x");
	rt += ft_puthex(i);
	return (rt);
}
