/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:28:10 by shan              #+#    #+#             */
/*   Updated: 2022/09/12 20:28:10 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_join(data->philo[i].thread_id, NULL))
			return (-1);
		i++;
	}
	if (pthread_join(data->manager, NULL))
		return (-1);
	return (0);
}

int	create_thread(t_data *data)
{
	int	i;

	i = 0;
	data->dead = 0;
	data->time = get_time();
	pthread_mutex_init(&data->print, NULL);
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->print);
		data->index = i;
		pthread_mutex_unlock(&data->print);
		if (pthread_create(&data->philo[i].thread_id, \
		NULL, &start_routine, data))
			return (-1);
		i++;
		usleep(10);
	}
	if (pthread_create(&data->manager, NULL, &manage, data))
		return (-1);
	usleep(10);
	if (join_thread(data))
		return (-1);
	return (0);
}

void	destroy_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->m_dead);
}
