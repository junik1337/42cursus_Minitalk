/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:51:26 by ayassir           #+#    #+#             */
/*   Updated: 2022/01/17 15:04:15 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nextargs(int i, const char *str, va_list ap)
{
	int		rt;

	rt = 0;
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		rt += ft_putnbr(va_arg(ap, int));
	if (str[i + 1] == 'u')
		rt += ft_putuns(va_arg(ap, unsigned int));
	if (str[i + 1] == 's')
		rt += ft_putstr(va_arg(ap, char *));
	if (str[i + 1] == 'c')
		rt += ft_putchar(va_arg(ap, int));
	if (str[i + 1] == 'x')
		rt += ft_puthex(va_arg(ap, unsigned int));
	if (str[i + 1] == 'X')
		rt += ft_puthexx(va_arg(ap, unsigned int));
	if (str[i + 1] == 'p')
		rt += ft_putptr(va_arg(ap, void *));
	return (rt);
}

int	ft_printf(const char *str, ...)
{
	va_list				ap;
	int					i;
	int					rtn;

	va_start(ap, str);
	i = 0;
	rtn = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			rtn += ft_putchar(str[i]);
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				rtn += ft_putchar('%');
			rtn += ft_nextargs(i, str, ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (rtn);
}
