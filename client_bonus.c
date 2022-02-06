/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:34:31 by ayassir           #+#    #+#             */
/*   Updated: 2022/01/19 18:30:51 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			g_i;

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

static void	send_bits(const char *message, int pid)
{
	int		shift;
	int		bits;
	int		rtrn;

	g_i = 0;
	while (message[g_i] != '\0')
	{	
		bits = 8;
		shift = 0;
		while (bits > 0)
		{
			if (message[g_i] << shift++ & 128)
				rtrn = kill(pid, SIGUSR1);
			else
				rtrn = kill(pid, SIGUSR2);
			bits--;
			usleep (500);
		}
		g_i++;
	}
	if (rtrn == -1)
	{
		g_i = 0;
		ft_printf("Error, invalid PID!");
	}
}

static void	my_handler(const char *str)
{
	if (str[g_i] == '\0')
	{
		ft_printf("-------------------------\n");
		ft_printf("%s\n", "Message sent successfully");
		ft_printf("-------------------------\n");
	}
}

int	main(int argc, char **argv)
{
	const char			*message;
	int					pid;

	if (argc == 3)
	{
		message = argv[2];
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf("Error, invalid PID!");
			exit (EXIT_FAILURE);
		}
		send_bits(message, pid);
		my_handler(message);
	}
	else
		ft_printf("YOU MUST HAVE 3 ARGUMENTS!\n");
	return (0);
}
