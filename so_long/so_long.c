/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 01:27:02 by shan              #+#    #+#             */
/*   Updated: 2022/07/10 23:33:29 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

int	ft_exit(t_data *data)
{
	write(1, "exit~ \n", 8);
	ft_free_map(data);
	exit (0);
	return (0);
}

void	ft_check(int ac, char **av)
{
	char	*s;

	if (ac != 2)
	{
		write(2, "ERROR\n", 6);
		exit (1);
	}
	if (ft_strrchr(av[1], '.') == 0)
		ft_error(3);
	s = ft_strrchr(av[1], '.');
	if (ft_strcmp(s, ".ber") != 0)
		ft_error(3);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	ft_check(ac, av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(1);
	data.map = ft_read_map(fd);
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, ft_strlen(data.map[0]) * 64,
			ft_mapelines(&data) * 64, "so_long");
	take_img(&data);
	count_collect(&data);
	draw_map(&data);
	mlx_hook(data.mlx_win, 2, 0, &take_key, &data);
	mlx_hook(data.mlx_win, 17, 0, &ft_exit, &data);
	mlx_loop_hook(data.mlx_ptr, draw_map, &data);
	mlx_loop(data.mlx_ptr);
}
