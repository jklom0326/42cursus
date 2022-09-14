/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:27:31 by shan              #+#    #+#             */
/*   Updated: 2022/09/12 20:27:31 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	data_init(t_data *data)
{
	data->eatcount = 0;
	data->eattime = 0;
	data->lifetime = 0;
	data->philo_num = 0;
	data->sleeptime = 0;
	data->eatcount_flag = 0;
	data->eat = 0;
	data->dead = 0;
}

void	fork_init(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_num + 1);
	while (i < data->philo_num)
	{
		pthread_mutex_init(&(data->fork[i]), NULL);
		i++;
	}
	pthread_mutex_init(&data->m_dead, NULL);
}

void	philo_init(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->philo_num + 1);
	while (i < data->philo_num)
	{
		data->philo[i].id = i;
		data->philo[i].fork.left = (i + 1) % data->philo_num;
		data->philo[i].fork.right = i;
		data->philo[i].eat_cnt = 0;
		i++;
	}
	fork_init(data);
}

void	unlock_fork(t_data *data, int i)
{
	pthread_mutex_lock(&data->m_dead);
	data->philo[i].eat_cnt++;
	pthread_mutex_unlock(&data->m_dead);
	pthread_mutex_unlock(&data->fork[data->philo[i].fork.left]);
	pthread_mutex_unlock(&data->fork[data->philo[i].fork.right]);
}
