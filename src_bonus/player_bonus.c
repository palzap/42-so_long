/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:48:51 by pealexan          #+#    #+#             */
/*   Updated: 2023/03/01 08:10:52 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	ft_load_player(t_values *v)
{
	v->pl.mvup = ft_load_image(v, "textures/player/mvup.xpm");
	v->pl.mvdown = ft_load_image(v, "textures/player/mvdown.xpm");
	v->pl.mvright = ft_load_image(v, "textures/player/mvright.xpm");
	v->pl.mvleft = ft_load_image(v, "textures/player/mvleft.xpm");
}

int	ft_move_up(t_values *v, int x, int y)
{
	v->i = 0;
	if (v->map[y][x] == '0' || v->map[y][x] == 'C')
	{
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img,
			v->player_x * SIZE, v->player_y * SIZE);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
			v->pl.mvup, x * SIZE, y * SIZE);
		if (v->map[y][x] == 'C')
			v->c--;
		v->map[v->player_y][v->player_x] = '0';
		v->map[y][x] = 'P';
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
	if (v->map[y][x] == '0' || v->map[y][x] == 'C')
	{
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img,
			v->player_x * SIZE, v->player_y * SIZE);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
			v->pl.mvdown, x * SIZE, y * SIZE);
		if (v->map[y][x] == 'C')
			v->c--;
		v->map[v->player_y][v->player_x] = '0';
		v->map[y][x] = 'P';
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
	if (v->map[y][x] == '0' || v->map[y][x] == 'C')
	{
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img,
			v->player_x * SIZE, v->player_y * SIZE);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
			v->pl.mvright, x * SIZE, y * SIZE);
		if (v->map[y][x] == 'C')
			v->c--;
		v->map[v->player_y][v->player_x] = '0';
		v->map[y][x] = 'P';
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
	if (v->map[y][x] == '0' || v->map[y][x] == 'C')
	{
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img,
			v->player_x * SIZE, v->player_y * SIZE);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
			v->pl.mvleft, x * SIZE, y * SIZE);
		if (v->map[y][x] == 'C')
			v->c--;
		v->map[v->player_y][v->player_x] = '0';
		v->map[y][x] = 'P';
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
