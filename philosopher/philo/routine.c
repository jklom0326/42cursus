/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:20:35 by shan              #+#    #+#             */
/*   Updated: 2022/09/12 20:20:35 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	routine_cnt(t_data *data, int i)
{
	while (1)
	{
		pthread_mutex_lock(&data->m_dead);
		if (!(data->dead == 0 && data->eatcount > data->philo[i].eat_cnt))
		{
			pthread_mutex_unlock(&data->m_dead);
			break ;
		}
		pthread_mutex_unlock(&data->m_dead);
		philo_eat(data, i);
		if (data->eatcount != data->philo[i].eat_cnt)
		{
			philo_sleep(data, i);
			philo_think(data, i);
		}
	}
}

void	routine(t_data *data, int i)
{
	while (1)
	{
		pthread_mutex_lock(&data->m_dead);
		if (data->dead != 0)
		{
			pthread_mutex_unlock(&data->m_dead);
			break ;
		}
		pthread_mutex_unlock(&data->m_dead);
		philo_eat(data, i);
		if (data->eatcount != data->philo[i].eat_cnt)
		{
			philo_sleep(data, i);
			philo_think(data, i);
		}
	}
}

void	*start_routine(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	pthread_mutex_lock(&data->print);
	i = data->index;
	pthread_mutex_unlock(&data->print);
	if (data->eatcount > 0)
		routine_cnt(data, i);
	else
		routine(data, i);
	return (0);
}

void	*manage(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	i = 0;
	if (data->eatcount > 0)
	{
		while (1)
		{
			pthread_mutex_lock(&data->m_dead);
			if (!(data->dead == 0 && data->eatcount > data->philo[i].eat_cnt))
			{
				pthread_mutex_unlock(&data->m_dead);
				break ;
			}
			pthread_mutex_unlock(&data->m_dead);
			philo_dead(data, &i);
		}
	}
	else
		while (data->dead == 0)
			philo_dead(data, &i);
	return (0);
}
