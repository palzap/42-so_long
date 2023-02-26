/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:57:15 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/26 09:06:43 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	ft_frames(t_values *v)
{
	char	*str;
	int		i;
	int		j;

	str = ft_itoa(v->moves);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->w_img, 32, 0);
	mlx_string_put(v->mlx_ptr, v->win_ptr, 35, 12, 0xFFFFFF, str);
	free(str);
	ft_animation(v);
	ft_hostile_move(v);
	i = 0;
	while (i < (v->map_y))
	{
		j = 0;
		while (j < v->map_x)
		{
			if (v->map[i][j] == 'E' && v->c == 0)
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->h_img, \
				j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_load_map2(t_values *v, int i, int j)
{
	if (v->map[i][j] == 'P')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->pl.mvup, \
		j * SIZE, i * SIZE);
	else if (v->map[i][j] == '0')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img, \
		j * SIZE, i * SIZE);
	else if (v->map[i][j] == 'H')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
		v->hostile.hdown, j * SIZE, i * SIZE);
}

void	ft_load_map(t_values *v)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (v->map_y))
	{
		j = -1;
		while (++j < v->map_x)
		{
			if (v->map[i][j] == '1')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->w_img, \
				j * SIZE, i * SIZE);
			else if (v->map[i][j] == 'C')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
				v->c_img, j * SIZE, i * SIZE);
			else if (v->map[i][j] == 'E')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->e_img, \
				j * SIZE, i * SIZE);
			else if (ft_strchr("P0H", v->map[i][j]))
				ft_load_map2(v, i, j);
		}
	}
}

void	ft_graphics(t_values *v)
{
	v->mlx_ptr = mlx_init ();
	if (!v->mlx_ptr)
		ft_error(v, "Error\nCould not allocate mlx_ptr\n");
	v->win_ptr = mlx_new_window(v->mlx_ptr, (v->map_x * SIZE),
			(v->map_y * SIZE), "so_long_bonus");
	if (!v->win_ptr)
		ft_error(v, "Error\nCould not allocate win_ptr\n");
	v->w_img = mlx_xpm_file_to_image(v->mlx_ptr, "textures/walls/SingleW.xpm",
			&v->img_x, &v->img_y);
	ft_load_player(v);
	ft_load_hostile(v);
	ft_load_animation(v);
	v->c_img = mlx_xpm_file_to_image(v->mlx_ptr, "textures/collectibles/c1.xpm",
			&v->img_x, &v->img_y);
	v->e_img = mlx_xpm_file_to_image(v->mlx_ptr, "textures/exit/closed.xpm",
			&v->img_x, &v->img_y);
	v->h_img = mlx_xpm_file_to_image(v->mlx_ptr, "textures/exit/open.xpm",
			&v->img_x, &v->img_y);
	v->f_img = mlx_xpm_file_to_image(v->mlx_ptr, "textures/floor1.xpm",
			&v->img_x, &v->img_y);
}

int	ft_check_move(int keycode, t_values *v)
	{
	if (keycode == ESC)
		ft_exit(v);
	else if (keycode == W)
		ft_move_up(v, v->player_x, v->player_y - 1);
	else if (keycode == A)
		ft_move_left(v, v->player_x - 1, v->player_y);
	else if (keycode == S)
		ft_move_down(v, v->player_x, v->player_y + 1);
	else if (keycode == D)
		ft_move_right(v, v->player_x + 1, v->player_y);
	return (0);
}
