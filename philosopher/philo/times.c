/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:39:32 by shan              #+#    #+#             */
/*   Updated: 2022/09/12 20:39:32 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	curr_time(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}

void	vsleep(unsigned int time)
{
	unsigned int	finish_time;

	finish_time = time + get_time();
	while (finish_time > (unsigned int)get_time())
		usleep(100);
}
