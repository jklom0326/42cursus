/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:52:58 by shan              #+#    #+#             */
/*   Updated: 2022/09/01 00:52:58 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	philo_eat(t_data *data, int i)
{
	if (i % 2 == 0)
	{
		pthread_mutex_lock(&data->fork[data->philo[i].fork.left]);
		philo_print(data, data->philo[i].id, "has taken a fork");
		pthread_mutex_lock(&data->fork[data->philo[i].fork.right]);
		philo_print(data, data->philo[i].id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&data->fork[data->philo[i].fork.right]);
		philo_print(data, data->philo[i].id, "has taken a fork");
		pthread_mutex_lock(&data->fork[data->philo[i].fork.left]);
		philo_print(data, data->philo[i].id, "has taken a fork");
	}
	philo_print(data, data->philo[i].id, "is eating");
	pthread_mutex_lock(&data->print);
	data->philo[i].dead_time = get_time();
	pthread_mutex_unlock(&data->print);
	vsleep(data->eattime);
	unlock_fork(data, i);
}

void	philo_sleep(t_data *data, int i)
{
	philo_print(data, data->philo[i].id, "is sleeping");
	vsleep(data->sleeptime);
}

void	philo_think(t_data *data, int i)
{
	philo_print(data, data->philo[i].id, "is thinking");
}

void	philo_dead(t_data *data, int *i)
{
	long long	time;

	if (*i == data->philo_num - 1)
		*i = 0;
	pthread_mutex_lock(&data->print);
	time = curr_time(data->philo[*i].dead_time);
	pthread_mutex_unlock(&data->print);
	if (time > data->lifetime)
	{
		philo_print(data, data->philo[*i].id, "died");
		pthread_mutex_lock(&data->m_dead);
		data->dead = 1;
		pthread_mutex_unlock(&data->m_dead);
	}
	(*i)++;
}
