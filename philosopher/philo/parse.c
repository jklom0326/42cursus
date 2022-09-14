/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:22:51 by shan              #+#    #+#             */
/*   Updated: 2022/09/12 20:22:51 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	philo_parse(char **av, t_data *data)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (ft_atoi(av[i]) == 0)
		{
			printf("num error\n");
			return (1);
		}
		i++;
	}
	data->philo_num = ft_atoi(av[1]);
	data->lifetime = ft_atoi(av[2]);
	data->eattime = ft_atoi(av[3]);
	data->sleeptime = ft_atoi(av[4]);
	return (0);
}

int	philo_with_eat_count_parse(char **av, t_data *data)
{
	int	i;

	i = 1;
	while (i < 6)
	{
		if (ft_atoi(av[i]) == 0)
		{
			printf("num error\n");
			return (1);
		}
		i++;
	}
	data->philo_num = ft_atoi(av[1]);
	data->lifetime = ft_atoi(av[2]);
	data->eattime = ft_atoi(av[3]);
	data->sleeptime = ft_atoi(av[4]);
	data->eatcount = ft_atoi(av[5]);
	data->eatcount_flag = 1;
	return (0);
}

int	parse(int ac, char **av, t_data *data)
{
	if (ac < 5 || ac > 6)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	if (ac == 5)
	{
		if (philo_parse(av, data))
			return (1);
	}
	else if (ac == 6)
	{
		if (philo_with_eat_count_parse(av, data))
			return (1);
	}
	return (0);
}
