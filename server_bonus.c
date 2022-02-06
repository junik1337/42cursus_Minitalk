/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:34:16 by ayassir           #+#    #+#             */
/*   Updated: 2022/01/19 16:13:53 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int			min;
	int			j;
	int			res;

	min = 1;
	j = 0;
	res = 0;
	while ((str[j] == '\t' || str [j] == '\n')
		|| (str[j] == '\v' || str [j] == '\f')
		|| (str[j] == '\r' || str [j] == ' '))
		j++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			min = -min;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		res = (res * 10) + (str[j] - '0');
		j++;
	}
	return (res * min);
}

static int	ft_decimal(char *str)
{
	int		num;
	int		base;
	int		decimal_num;
	int		rem;

	num = ft_atoi(str);
	base = 1;
	rem = 0;
	decimal_num = 0;
	while (num > 0)
	{
		rem = num % 10;
		decimal_num = decimal_num + rem * base;
		num = num / 10;
		base = base * 2;
	}
	return (decimal_num);
}

static void	my_handler(int signum, siginfo_t *siginfo, void *param)
{
	char			bits[9];
	static int		i;
	static int		pid;
	int				decimal;

	(void) param;
	if (!pid)
		pid = siginfo->si_pid;
	if (pid != siginfo->si_pid)
	{
		pid = siginfo->si_pid;
		i = 0;
	}
	if (signum == SIGUSR1)
		bits[i++] = '1';
	else if (signum == SIGUSR2)
		bits[i++] = '0';
	if (i == 8)
	{
		bits[i] = '\0';
		decimal = ft_decimal(bits);
		write(1, &decimal, 1);
		i = 0;
	}
}

int	main(int argc, char **argv)
{		
	struct sigaction	sa;
	int					rtrn;

	(void) argv;
	if (argc > 1)
		return (0);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &my_handler;
	rtrn = sigaction(SIGUSR1, &sa, NULL);
	if (rtrn == -1)
	{
		ft_printf("Signal error.");
		exit (EXIT_FAILURE);
	}
	rtrn = sigaction(SIGUSR2, &sa, NULL);
	if (rtrn == -1)
	{
		ft_printf("Signal error.");
		exit (EXIT_FAILURE);
	}
	ft_printf("-----------\nPID : %d\n-----------\n\n", getpid());
	while (1)
		pause ();
	return (0);
}
