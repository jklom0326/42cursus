/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:52:53 by shan              #+#    #+#             */
/*   Updated: 2022/07/04 16:52:53 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr("-214748364");
		n = 8;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

int	ft_count_line(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			c++;
		i++;
	}
	return (c);
}

int	ft_mapelines(t_data *n)
{
	int	i;

	i = 0;
	while (n->map[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s, char *p)
{
	int	i;

	i = 0;
	while (s[i] && p[i] && s[i] == p[i])
		i++;
	return (s[i] - p[i]);
}

void	ft_error(int n)
{
	if (n == 1)
		write(2, "Error in fd\n", 13);
	if (n == 2)
		write(2, "Error in map\n", 13);
	if (n == 3)
		write(2, "Error in path\n", 15);
	exit(1);
}
