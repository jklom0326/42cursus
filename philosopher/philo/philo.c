/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:35:15 by shan              #+#    #+#             */
/*   Updated: 2022/08/31 00:40:48 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	philos(t_data *data)
{
	pthread_mutex_init(&data->print, NULL);
	data->time = get_time();
	philo_print(data, 0, "has taken a fork");
	usleep(1000 * data->lifetime);
	philo_print(data, 0, "died");
	free_all(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	data_init(&data);
	if (parse(ac, av, &data))
		return (1);
	philo_init(&data);
	if (data.philo_num == 1)
	{
		philos(&data);
		return (0);
	}
	if (create_thread(&data) == -1)
	{
		free_all(&data);
		printf("Fail to create thread\n");
		return (1);
	}
	destroy_thread(&data);
	free_all(&data);
}
