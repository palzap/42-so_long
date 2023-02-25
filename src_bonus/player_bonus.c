/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:48:51 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/25 01:38:59 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	ft_load_player(t_values *v)
{
	v->pl.mvup = mlx_xpm_file_to_image(v->mlx_ptr, \
	"textures/player/mvup.xpm", &v->img_x, &v->img_y);
	v->pl.mvdown = mlx_xpm_file_to_image(v->mlx_ptr, \
	"textures/player/mvdown.xpm", &v->img_x, &v->img_y);
	v->pl.mvright = mlx_xpm_file_to_image(v->mlx_ptr, \
	"textures/player/mvright.xpm", &v->img_x, &v->img_y);
	v->pl.mvleft = mlx_xpm_file_to_image(v->mlx_ptr, \
	"textures/player/mvleft.xpm", &v->img_x, &v->img_y);
}

int	ft_move_up(t_values *v, int x, int y)
{
	v->i = 0;
	ft_move_hostileleft(v);
	if (v->map[y][x] == '0' || v->map[y][x] == 'C')
	{
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img,
			v->player_x * SIZE, v->player_y * SIZE);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
			v->pl.mvup, x * SIZE, y * SIZE);
		if (v->map[y][x] == 'C')
			v->c--;
		v->map[v->player_y][v->player_x] = '0';
		v->map[y][x] = '0';
		v->player_x = x;
		v->player_y = y;
		v->moves++;
		return (1);
	}
	else if ((v->map[y][x] == 'E' && !v->c) || v->map[y][x] == 'H')
	{
		v->moves++;
		ft_exit(v);
	}
	return (0);
}

int	ft_move_down(t_values *v, int x, int y)
{
	v->i = 0;
	ft_move_hostileup(v);
	if (v->map[y][x] == '0' || v->map[y][x] == 'C')
	{
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img,
			v->player_x * SIZE, v->player_y * SIZE);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
			v->pl.mvdown, x * SIZE, y * SIZE);
		if (v->map[y][x] == 'C')
			v->c--;
		v->map[v->player_y][v->player_x] = '0';
		v->map[y][x] = '0';
		v->player_x = x;
		v->player_y = y;
		v->moves++;
		return (1);
	}
	else if ((v->map[y][x] == 'E' && !v->c) || v->map[y][x] == 'H')
	{
		v->moves++;
		ft_exit(v);
	}
	return (0);
}

int	ft_move_right(t_values *v, int x, int y)
{
	v->i = 0;
	ft_move_hostiledown(v);
	if (v->map[y][x] == '0' || v->map[y][x] == 'C')
	{
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img,
			v->player_x * SIZE, v->player_y * SIZE);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
			v->pl.mvright, x * SIZE, y * SIZE);
		if (v->map[y][x] == 'C')
			v->c--;
		v->map[v->player_y][v->player_x] = '0';
		v->map[y][x] = '0';
		v->player_x = x;
		v->player_y = y;
		v->moves++;
		return (1);
	}
	else if ((v->map[y][x] == 'E' && !v->c) || v->map[y][x] == 'H')
	{
		v->moves++;
		ft_exit(v);
	}
	return (0);
}

int	ft_move_left(t_values *v, int x, int y)
{
	v->i = 0;
	ft_move_hostileright(v);
	if (v->map[y][x] == '0' || v->map[y][x] == 'C')
	{
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img,
			v->player_x * SIZE, v->player_y * SIZE);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
			v->pl.mvleft, x * SIZE, y * SIZE);
		if (v->map[y][x] == 'C')
			v->c--;
		v->map[v->player_y][v->player_x] = '0';
		v->map[y][x] = '0';
		v->player_x = x;
		v->player_y = y;
		v->moves++;
		return (1);
	}
	else if ((v->map[y][x] == 'E' && !v->c) || v->map[y][x] == 'H')
	{
		v->moves++;
		ft_exit(v);
	}
	return (0);
}
