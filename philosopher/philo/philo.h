/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:35:37 by shan              #+#    #+#             */
/*   Updated: 2022/08/31 01:24:57 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_fork
{
	int			left;
	int			right;
}t_fork;

typedef struct s_philo
{
	int			id;
	int			eat_cnt;
	long long	dead_time;
	pthread_t	thread_id;
	t_fork		fork;
}t_philo;

typedef struct s_data
{
	int				philo_num;
	int				lifetime;
	int				eattime;
	int				sleeptime;
	int				eatcount;
	int				eatcount_flag;
	long long		time;
	int				index;
	int				eat;
	int				dead;
	pthread_t		manager;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	m_dead;
	t_philo			*philo;
}t_data;

// parse.c
int			parse(int ac, char **av, t_data *p);

// thread_init.c 
int			create_thread(t_data *data);
void		destroy_thread(t_data *data);

// routine.c 
void		*start_routine(void *args);
void		*manage(void *args);
void		philo_print(t_data *data, int id, char *print);

// philo_action.c 
void		philo_eat(t_data *data, int i);
void		philo_sleep(t_data *data, int i);
void		philo_think(t_data *data, int i);
void		philo_dead(t_data *data, int *i);

// philos_init.c 
void		data_init(t_data *p);
void		fork_init(t_data *data);
void		philo_init(t_data *data);
void		unlock_fork(t_data *data, int i);

// utils.c 
int			ft_atoi(const char *str);
void		free_all(t_data *data);
void		philo_print(t_data *data, int id, char *print);

// get_time.c 
long long	get_time(void);
long long	curr_time(long long time);
void		vsleep(unsigned int time);

#endif
