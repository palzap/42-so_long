/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:34:48 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/23 15:51:14 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_check_file(char *file, t_values *v)
{
	int	fd;

	fd = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_putstr_fd("Error\nFile doesn't exist\n", 2);
		exit(1);
	}
	v->i = ft_strlen(file) - 1;
	while (file[v->i] != '.')
		v->i--;
	if (ft_strncmp((file + v->i), ".ber", 4))
	{
		ft_putstr_fd("Error\nInvalid file type\n", 2);
		exit (1);
	}
	close(fd);
	ft_get_x_y(file, v);
}

void	ft_init_struct(t_values *v)
{
	v->mlx_ptr = 0;
	v->win_ptr = 0;
	v->map = 0;
	v->w_img = 0;
	v->p_img = 0;
	v->c_img = 0;
	v->e_img = 0;
	v->h_img = 0;
	v->map_x = 0;
	v->map_y = 0;
	v->img_x = 0;
	v->img_y = 0;
	v->player_x = 0;
	v->player_y = 0;
	v->p = 0;
	v->c = 0;
	v->e = 0;
	v->h = 0;
	v->i = 0;
	v->j = 0;
	v->moves = 0;
}

int	main(int argc, char **argv)
{
	t_values	v;

	ft_init_struct(&v);
	if (argc == 2)
	{
		ft_check_file(argv[1], &v);
		ft_graphics(&v);
		ft_load_map(&v);
		mlx_hook(v.win_ptr, 17, 0, ft_exit, &v);
		mlx_hook(v.win_ptr, KeyPress, KeyPressMask, ft_check_move, &v);
		mlx_loop(v.mlx_ptr);
	}
	return (0);
}
