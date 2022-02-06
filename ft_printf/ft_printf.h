/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:48:31 by ayassir           #+#    #+#             */
/*   Updated: 2022/01/18 19:28:46 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putuns(unsigned int n);
int		ft_puthex(unsigned long i);
int		ft_puthexx(unsigned long i);
int		ft_putptr(void *str);

#endif