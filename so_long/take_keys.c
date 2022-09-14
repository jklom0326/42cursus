/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:13:45 by shan              #+#    #+#             */
/*   Updated: 2022/07/10 23:25:25 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	key_0(t_data *map, int *c)
{
	int		x;
	int		y;

	get_index(map, &x, &y);
	if (*c == 0)
		map->cave = map->cave_in;
	if (map->map[y][x - 1] == 'C')
	{
		map->map[y][x - 1] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (map->map[y][x - 1] == '0')
	{
		map->map[y][x - 1] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
	}
	if (map->map[y][x - 1] == 'E' && *c == 0)
		ft_game_msg(1, map);
}

void	key_1(t_data *map, int *c)
{
	int		x;
	int		y;

	get_index(map, &x, &y);
	if (*c == 0)
		map->cave = map->cave_in;
	if (map->map[y + 1][x] == 'C')
	{
		map->map[y + 1][x] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (map->map[y + 1][x] == '0')
	{
		map->map[y + 1][x] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
	}
	if (map->map[y + 1][x] == 'E' && *c == 0)
		ft_game_msg(1, map);
}

void	key_2(t_data *map, int *c)
{
	int		x;
	int		y;

	get_index(map, &x, &y);
	if (*c == 0)
		map->cave = map->cave_in;
	if (map->map[y][x + 1] == 'C')
	{
		map->map[y][x + 1] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (map->map[y][x + 1] == '0')
	{
		map->map[y][x + 1] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
	}
	if (map->map[y][x + 1] == 'E' && *c == 0)
		ft_game_msg(1, map);
}

void	key_13(t_data *map, int *c)
{
	int		x;
	int		y;

	get_index(map, &x, &y);
	if (*c == 0)
		map->cave = map->cave_in;
	if (map->map[y - 1][x] == 'C')
	{
		map->map[y - 1][x] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (map->map[y - 1][x] == '0')
	{
		map->map[y - 1][x] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
	}
	if (map->map[y - 1][x] == 'E' && *c == 0)
		ft_game_msg(1, map);
}

int	take_key(int key, t_data *m)
{
	if (key == 97)
		key_0(m, &m->c);
	if (key == 115)
		key_1(m, &m->c);
	if (key == 100)
		key_2(m, &m->c);
	if (key == 119)
		key_13(m, &m->c);
	if (key == 65307)
		ft_exit(m);
	return (key);
}
