/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 02:25:23 by shan              #+#    #+#             */
/*   Updated: 2022/07/10 23:31:59 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_img(t_data *data)
{
	data->trainer = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./img/trainer1.xpm", &data->a, &data->b);
	data->rival = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./img/rival1.xpm", &data->a, &data->b);
	data->cave_in = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./img/cave_in.xpm", &data->a, &data->b);
	data->cave = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./img/cave.xpm", &data->a, &data->b);
	data->monster_ball = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./img/monster_ball.xpm", &data->a, &data->b);
	data->tree = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./img/tree.xpm", &data->a, &data->b);
	data->ground = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./img/ground.xpm", &data->a, &data->b);
}

void	move_trainer(t_data *m)
{
	static int	i;
	static int	j;

	if (i % 10 == 0)
	{
		if (j)
		{
			j = 0;
			m->trainer = mlx_xpm_file_to_image(m->mlx_ptr, \
					"./img/trainer1.xpm", &m->a, &m->b);
		}
		else
		{
			j = 1;
			m->trainer = mlx_xpm_file_to_image(m->mlx_ptr, \
					"./img/trainer2.xpm", &m->a, &m->b);
		}
	}
	if (i == 100000)
		i = 0;
	i++;
}

void	draw_map_2(t_data *data, int j)
{
	if (data->map[data->i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
				data->tree, j * 64, data->i * 64);
	if (data->map[data->i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
				data->ground, j * 64, data->i * 64);
	if (data->map[data->i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
				data->monster_ball, j * 64, data->i * 64);
	if (data->map[data->i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
				data->cave, j * 64, data->i * 64);
	if (data->map[data->i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
				data->trainer, j * 64, data->i * 64);
	if (data->map[data->i][j] == 'F')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
				data->rival, j * 64, data->i * 64);
}

int	draw_map(t_data *data)
{
	int	j;

	data->i = 0;
	move_trainer(data);
	while (data->map[data->i])
	{
		j = 0;
		while (data->map[data->i][j])
		{
			draw_map_2(data, j);
			j++;
		}
		data->i++;
	}
	return (0);
}
