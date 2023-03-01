/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:57:15 by pealexan          #+#    #+#             */
/*   Updated: 2023/03/01 08:05:56 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	*ft_load_image(t_values *v, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(v->mlx_ptr, path,
			&v->img_x, &v->img_y);
	if (!img)
	{
		ft_putstr_fd("Error\nCould not allocate memory for image\n", 2);
		ft_exit(v);
	}
	return (img);
}

void	ft_load_map(t_values *v)
{
	v->i = 0;
	while (v->i < (v->map_y))
	{
		v->j = 0;
		while (v->j < v->map_x)
		{
			if (v->map[v->i][v->j] == '1')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
					v->w_img, v->j * SIZE, v->i * SIZE);
			else if (v->map[v->i][v->j] == 'C')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->c_img,
					v->j * SIZE, v->i * SIZE);
			else if (v->map[v->i][v->j] == 'E')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
					v->e_img, v->j * SIZE, v->i * SIZE);
			else if (v->map[v->i][v->j] == 'P')
				mlx_put_image_to_window(v->mlx_ptr,
					v->win_ptr, v->p_img, v->j * SIZE, v->i * SIZE);
			else
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
					v->f_img, v->j * SIZE, v->i * SIZE);
			v->j++;
		}
		v->i++;
	}
}

void	ft_graphics(t_values *v)
{
	v->mlx_ptr = mlx_init ();
	if (!v->mlx_ptr)
		ft_error(v, "Error\nCould not allocate mlx_ptr\n");
	v->win_ptr = mlx_new_window(v->mlx_ptr, (v->map_x * SIZE),
			(v->map_y * SIZE), "so_long");
	if (!v->win_ptr)
	{
		mlx_destroy_display(v->mlx_ptr);
		free(v->mlx_ptr);
		ft_error(v, "Error\nCould not allocate win_ptr\n");
	}
	v->w_img = ft_load_image(v, "textures/wall.xpm");
	v->p_img = ft_load_image(v, "textures/player.xpm");
	v->c_img = ft_load_image(v, "textures/collectible.xpm");
	v->e_img = ft_load_image(v, "textures/exit.xpm");
	v->f_img = ft_load_image(v, "textures/floor.xpm");
}

int	ft_move_player(t_values *v, int x, int y)
{
	v->i = 0;
	if (v->map[y][x] == '0' || v->map[y][x] == 'C')
	{
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img,
			v->player_x * SIZE, v->player_y * SIZE);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr,
			v->p_img, x * SIZE, y * SIZE);
		if (v->map[y][x] == 'C')
			v->c--;
		v->map[v->player_y][v->player_x] = '0';
		v->map[y][x] = '0';
		v->player_x = x;
		v->player_y = y;
		v->moves++;
		return (1);
	}
	else if (v->map[y][x] == 'E' && !v->c)
	{
		ft_printf("Moves: %i\n", v->moves + 1);
		ft_exit(v);
	}
	return (0);
}

int	ft_check_move(int keycode, t_values *v)
	{
	int	flag;

	flag = 0;
	if (keycode == ESC)
		ft_exit(v);
	else if (keycode == W)
		flag = ft_move_player(v, v->player_x, v->player_y - 1);
	else if (keycode == A)
		flag = ft_move_player(v, v->player_x - 1, v->player_y);
	else if (keycode == S)
		flag = ft_move_player(v, v->player_x, v->player_y + 1);
	else if (keycode == D)
		flag = ft_move_player(v, v->player_x + 1, v->player_y);
	if (flag == 1)
		ft_printf("Moves: %i\n", v->moves);
	return (0);
}
