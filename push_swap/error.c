/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:37:19 by shan              #+#    #+#             */
/*   Updated: 2022/07/16 14:37:19 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	error(void)
{
	char	*error;
	char	temp;

	error = "Error";
	temp = '\n';
	write(1, error, 5);
	write(1, &temp, 1);
	exit(1);
}

void	error_isbigger(int ac, char *av[])
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_atoi(av[i]) > 2147483647)
			error();
		else if (ft_atoi(av[i]) < -2147483648)
			error();
		i++;
	}
}

void	error_isduplic(int ac, char *av[])
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
			if (ft_strcmp(av[i], av[j++]))
				error();
		i++;
	}
}

void	error_isnumber(int ac, char *av[])
{
	int		i;
	int		j;
	int		lenght;
	char	*string;

	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		string = av[i++ + 1];
		lenght = ft_strlen(string);
		if (lenght == 0)
			error();
		while (j < lenght)
		{
			if (!ischardigit(string[j++]))
				error();
		}
	}
}

void	error_isonearg(int ac)
{
	if (ac == 1)
		exit(1);
}
