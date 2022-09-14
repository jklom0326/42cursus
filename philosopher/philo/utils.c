/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:52:28 by shan              #+#    #+#             */
/*   Updated: 2022/09/01 00:52:28 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (n < 0 || ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		|| n > 2147483647)
		return (0);
	return (n);
}

void	free_all(t_data *data)
{
	free(data->philo);
	free(data->fork);
}

void	philo_print(t_data *data, int id, char *print)
{
	long long	current;

	current = curr_time(data->time);
	pthread_mutex_lock(&data->m_dead);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->m_dead);
		return ;
	}
	pthread_mutex_unlock(&data->m_dead);
	pthread_mutex_lock(&data->m_dead);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->m_dead);
		return ;
	}
	else
		printf("%lld %d %s\n", current, id + 1, print);
	pthread_mutex_unlock(&data->m_dead);
}
