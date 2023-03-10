/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hostile_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:49:50 by pealexan          #+#    #+#             */
/*   Updated: 2023/03/01 08:12:27 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	ft_load_hostile(t_values *v)
{
	v->hostile.hup = ft_load_image(v, "textures/hostile/hup.xpm");
	v->hostile.hdown = ft_load_image(v, "textures/hostile/hdown.xpm");
	v->hostile.hright = ft_load_image(v, "textures/hostile/hright.xpm");
	v->hostile.hleft = ft_load_image(v, "textures/hostile/hleft.xpm");
}

void	ft_move_hostileright(t_values *v)
{
	v->i = 0;
	while (v->i < (v->map_y))
	{
		v->j = 0;
		while (v->j < v->map_x)
		{
			if (v->map[v->i][v->j] == 'H' && v->map[v->i][v->j + 1] == 'P')
				ft_exit(v);
			if (v->map[v->i][v->j] == 'H' && v->map[v->i][v->j + 1] == '0')
			{
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->f_img, \
				v->j * SIZE, v->i * SIZE);
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
				v->hostile.hright, (v->j + 1) * SIZE, v->i * SIZE);
				v->map[v->i][v->j] = '0';
				v->map[v->i][v->j + 1] = 'H';
				break ;
			}
			v->j++;
		}
		v->i++;
	}
}

void	ft_move_hostileleft(t_values *v)
{
	v->i = 0;
	while (v->i < (v->map_y))
	{
		v->j = 0;
		while (v->j < v->map_x)
		{
			if (v->map[v->i][v->j] == 'H' && v->map[v->i][v->j -1] == 'P')
				ft_exit(v);
			if (v->map[v->i][v->j] == 'H' && v->map[v->i][v->j - 1] == '0')
			{
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
				v->f_img, v->j * SIZE, v->i * SIZE);
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
				v->hostile.hleft, (v->j - 1) * SIZE, v->i * SIZE);
				v->map[v->i][v->j] = '0';
				v->map[v->i][v->j - 1] = 'H';
				break ;
			}
			v->j++;
		}
		v->i++;
	}
}

void	ft_move_hostileup(t_values *v)
{
	v->i = 0;
	while (v->i < (v->map_y))
	{
		v->j = 0;
		while (v->j < v->map_x)
		{
			if (v->map[v->i][v->j] == 'H' && v->map[v->i - 1][v->j] == 'P')
				ft_exit(v);
			if (v->map[v->i][v->j] == 'H' && v->map[v->i - 1][v->j] == '0')
			{
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
				v->f_img, v->j * SIZE, v->i * SIZE);
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
				v->hostile.hup, v->j * SIZE, (v->i - 1) * SIZE);
				v->map[v->i][v->j] = '0';
				v->map[v->i - 1][v->j] = 'H';
				break ;
			}
			v->j++;
		}
		v->i++;
	}
}

void	ft_move_hostiledown(t_values *v)
{
	int	flag;

	v->i = -1;
	flag = 0;
	while (++v->i < (v->map_y))
	{
		v->j = -1;
		while (++v->j < v->map_x)
		{
			if (v->map[v->i][v->j] == 'H' && v->map[v->i + 1][v->j] == 'P')
				ft_exit(v);
			if (v->map[v->i][v->j] == 'H' && v->map[v->i + 1][v->j] == '0' \
			&& flag == 0)
			{
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
				v->f_img, v->j * SIZE, v->i * SIZE);
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, \
				v->hostile.hdown, v->j * SIZE, (v->i + 1) * SIZE);
				v->map[v->i][v->j] = '0';
				v->map[v->i + 1][v->j] = 'H';
				flag = 1;
				break ;
			}
		}
	}
}
