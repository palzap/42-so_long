/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:21:28 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/26 09:31:26 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	ft_animation1(t_values *v)
{
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall1, \
	0, 0);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall1, \
	0, (v->map_y - 1) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall1, \
	(v->map_x - 1) * SIZE, 0);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall1, \
	(v->map_x - 1) * SIZE, (v->map_y - 1) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall1, \
	0, (v->map_y / 2) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall1, \
	(v->map_x - 1) * SIZE, (v->map_y / 2) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall1, \
	(v->map_x / 2) * SIZE, 0);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall1, \
	(v->map_x / 2) * SIZE, (v->map_y - 1) * SIZE);
}

void	ft_animation2(t_values *v)
{
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall2, \
	0, 0);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall2, \
	0, (v->map_y - 1) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall2, \
	(v->map_x - 1) * SIZE, 0);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall2, \
	(v->map_x - 1) * SIZE, (v->map_y - 1) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall2, \
	0, (v->map_y / 2) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall2, \
	(v->map_x - 1) * SIZE, (v->map_y / 2) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall2, \
	(v->map_x / 2) * SIZE, 0);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall2, \
	(v->map_x / 2) * SIZE, (v->map_y - 1) * SIZE);
}

void	ft_animation3(t_values *v)
{
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall3, \
	0, 0);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall3, \
	0, (v->map_y - 1) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall3, \
	(v->map_x - 1) * SIZE, 0);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall3, \
	(v->map_x - 1) * SIZE, (v->map_y - 1) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall3, \
	0, (v->map_y / 2) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall3, \
	(v->map_x - 1) * SIZE, (v->map_y / 2) * SIZE);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall3, \
	(v->map_x / 2) * SIZE, 0);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->animate.wall3, \
	(v->map_x / 2) * SIZE, (v->map_y - 1) * SIZE);
}

void	ft_animation(t_values *v)
{
	static int	i;

	i++;
	if (i == 5000)
		ft_animation1(v);
	if (i == 10000)
		ft_animation2(v);
	if (i == 15000)
	{
		ft_animation3(v);
		i = 0;
	}
}

void	ft_load_animation(t_values *v)
{
	v->animate.wall1 = mlx_xpm_file_to_image(v->mlx_ptr, \
	"textures/walls/SingleW1.xpm", &v->img_x, &v->img_y);
	v->animate.wall2 = mlx_xpm_file_to_image(v->mlx_ptr, \
	"textures/walls/SingleW2.xpm", &v->img_x, &v->img_y);
	v->animate.wall3 = mlx_xpm_file_to_image(v->mlx_ptr, \
	"textures/walls/SingleW3.xpm", &v->img_x, &v->img_y);
}
