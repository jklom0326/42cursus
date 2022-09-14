/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:43:27 by shan              #+#    #+#             */
/*   Updated: 2022/06/13 17:51:33 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	sft(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr("success\n");
}

void	binary(int pid, char *s)
{
	int	i;
	int	bit;

	i = 0;
	if (!s)
		exit(1);
	while (1)
	{
		bit = -1;
		while (++bit < 9)
		{
			ft_kill(bit, pid, s[i]);
			usleep(100);
		}
		if (!s[i])
			break ;
		i++;
	}
}

void	ft_kill(int bit, int pid, char c)
{
	if (c & (128 >> bit))
	{
		if (kill(pid, SIGUSR1) == -1)
			exit(1);
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3 || av[2][0] == '\0')
	{
		write(1, "error\n", 6);
		exit(1);
	}
	signal(SIGUSR1, sft);
	pid = ft_atoi(av[1]);
	if (pid == -1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	binary(pid, av[2]);
}
