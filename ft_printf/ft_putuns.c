/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:45:02 by ayassir           #+#    #+#             */
/*   Updated: 2022/01/17 15:04:40 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int n)
{
	int				nbr;
	int				rt;

	nbr = n;
	rt = 0;
	if (n < 0)
		return (rt);
	if (n <= 9 && n >= 0)
	{
		nbr = n + 48;
		rt += write(1, &nbr, 1);
	}
	if (n > 9)
	{
		rt += ft_putnbr(n / 10);
		rt += ft_putnbr(n % 10);
	}
	return (rt);
}
