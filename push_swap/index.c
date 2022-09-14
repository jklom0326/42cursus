/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:50:23 by shan              #+#    #+#             */
/*   Updated: 2022/07/17 01:50:23 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

t_index	*fill_array(int ac, t_index *array, int i, int j)
{
	long		minor;
	long		major;

	major = -2147483649;
	while (j < ac - 1)
	{
		minor = 2147483648;
		while (++i < ac - 1)
		{
			if (array[i].value > major && array[i].value <= minor)
			{
				minor = array[i].value;
				array[i].index = j;
			}
		}
		j++;
		major = minor;
		i = -1;
	}
	return (array);
}

int	*index_it(int ac, char *av[])
{
	int		i;
	int		j;
	int		*return_it;
	t_index	*array;

	array = (t_index *)malloc(sizeof(t_index) * (ac - 1));
	return_it = (int *)malloc(sizeof(int) * (ac - 1));
	i = -1;
	j = 0;
	while (++i < ac - 1)
		array[i].value = atoi(av[i + 1]);
	i = -1;
	array = fill_array(ac, array, i, j);
	while (++i < ac - 1)
		return_it[i] = array[i].index;
	free(array);
	return (return_it);
}

t_index	*fill_array_2(int ac, t_index *array, int i, int j)
{
	long		minor;
	long		major;

	major = -2147483649;
	while (j < ac)
	{
		minor = 2147483648;
		while (++i < ac)
		{
			if (array[i].value > major && array[i].value <= minor)
			{
				minor = array[i].value;
				array[i].index = j;
			}
		}
		j++;
		major = minor;
		i = -1;
	}
	return (array);
}

int	*index_it_2(int ac, char *av[])
{
	int		i;
	int		j;
	int		*return_it;
	t_index	*array;

	array = (t_index *)malloc(sizeof(t_index) * (ac));
	if (!(array))
		return (NULL);
	return_it = (int *)malloc(sizeof(int) * (ac));
	if (!(return_it))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ac)
		array[i].value = ft_atoi(av[i]);
	i = -1;
	array = fill_array_2(ac, array, i, j);
	while (++i < ac)
		return_it[i] = array[i].index;
	free(array);
	return (return_it);
}
