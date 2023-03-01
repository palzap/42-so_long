/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:04 by pealexan          #+#    #+#             */
/*   Updated: 2023/03/01 08:02:50 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
	if (v->w_img)
		mlx_destroy_image(v->mlx_ptr, v->w_img);
	if (v->p_img)
		mlx_destroy_image(v->mlx_ptr, v->p_img);
	if (v->c_img)
		mlx_destroy_image(v->mlx_ptr, v->c_img);
	if (v->e_img)
		mlx_destroy_image(v->mlx_ptr, v->e_img);
	if (v->f_img)
		mlx_destroy_image(v->mlx_ptr, v->f_img);
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
