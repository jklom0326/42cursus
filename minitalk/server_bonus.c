/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:40:31 by shan              #+#    #+#             */
/*   Updated: 2022/06/13 02:48:12 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

void	failmassage(int pid, int signum)
{
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	bitaction(int signum, siginfo_t *info, void *context)
{
	static int	g_pid = 0;
	static char	c = 0xFF;
	static int	bit = 0;

	(void) context;
	if (g_pid != info->si_pid)
	{
		c = 0xFF;
		bit = 0;
		g_pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		c |= 0x80 >> bit;
	else if (signum == SIGUSR2)
		c ^= 0x80 >> bit;
	if (bit++ == 8)
	{
		if (!c)
			failmassage(g_pid, SIGUSR1);
		ft_putchar(c);
		bit = 0;
		c = 0xFF;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 1 || av[1] != NULL)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	sa.sa_sigaction = bitaction;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
