/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:57:15 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/25 03:13:16 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	ft_frames(t_values *v)
{
	char	*str;

	str = ft_itoa(v->moves);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->w_img, 32, 0);
	mlx_string_put(v->mlx_ptr, v->win_ptr, 35, 12, 0xFFFFFF, str);
	free(str);
	ft_animation(v);
	v->i = 0;
	while (v->i < (v->map_y))
	{
		v->j = 0;
		while (v->j < v->map_x)
		{
			if (v->map[v->i][v->j] == 'E' && v->c == 0)
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->h_img, \
				v->j * SIZE, v->i * SIZE);
			v->j++;
		}
		v->i++;
	}
	return (0);
}

void	ft_load_map2(t_values *v)
{
	if (v->map[v->i][v->j] == 'P')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->pl.mvup, \
		v->j * SIZE, v->i * SIZE);
	else if (v->map[v->i][v->j] == '0')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img, \
		v->j * SIZE, v->i * SIZE);
	else if (v->map[v->i][v->j] == 'H')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
		v->hostile.hdown, v->j * SIZE, v->i * SIZE);
}

void	ft_load_map(t_values *v)
{
	v->i = -1;
	while (++v->i < (v->map_y))
	{
		v->j = -1;
		while (++v->j < v->map_x)
		{
			if (v->map[v->i][v->j] == '1')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->w_img, \
				v->j * SIZE, v->i * SIZE);
			else if (v->map[v->i][v->j] == 'C')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
				v->c_img, v->j * SIZE, v->i * SIZE);
			else if (v->map[v->i][v->j] == 'E')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->e_img, \
				v->j * SIZE, v->i * SIZE);
			else if (ft_strchr("P0H", v->map[v->i][v->j]))
				ft_load_map2(v);
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
