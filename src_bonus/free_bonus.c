/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:04 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/25 02:54:03 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	ft_free_map(t_values *v)
{
	int	i;

	i = 0;
	while (v->map[i])
		free(v->map[i++]);
	free(v->map);
}

void	ft_error(t_values *v, char *msg)
{
	ft_free_map(v);
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	ft_destroy_images(t_values *v)
{
	mlx_destroy_image(v->mlx_ptr, v->pl.mvup);
	mlx_destroy_image(v->mlx_ptr, v->pl.mvdown);
	mlx_destroy_image(v->mlx_ptr, v->pl.mvright);
	mlx_destroy_image(v->mlx_ptr, v->pl.mvleft);
	mlx_destroy_image(v->mlx_ptr, v->hostile.hup);
	mlx_destroy_image(v->mlx_ptr, v->hostile.hdown);
	mlx_destroy_image(v->mlx_ptr, v->hostile.hright);
	mlx_destroy_image(v->mlx_ptr, v->hostile.hleft);
	mlx_destroy_image(v->mlx_ptr, v->w_img);
	mlx_destroy_image(v->mlx_ptr, v->c_img);
	mlx_destroy_image(v->mlx_ptr, v->animate.wall1);
	mlx_destroy_image(v->mlx_ptr, v->animate.wall2);
	mlx_destroy_image(v->mlx_ptr, v->animate.wall3);
	mlx_destroy_image(v->mlx_ptr, v->e_img);
	mlx_destroy_image(v->mlx_ptr, v->f_img);
	mlx_destroy_image(v->mlx_ptr, v->h_img);
}

int	ft_exit(t_values *v)
{
	ft_destroy_images(v);
	mlx_destroy_window(v->mlx_ptr, v->win_ptr);
	mlx_destroy_display(v->mlx_ptr);
	free(v->mlx_ptr);
	ft_free_split(v->map);
	exit(0);
}
