/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:34:48 by pealexan          #+#    #+#             */
/*   Updated: 2023/03/01 08:08:02 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

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

void	ft_hostile_move(t_values *v)
{
	int			random;
	static int	i;

	i++;
	random = 0;
	srand(time(0));
	if (i == 5000)
	{
		random = rand() % 4;
		if (random == 0)
			ft_move_hostileleft(v);
		else if (random == 1)
			ft_move_hostileup(v);
		else if (random == 2)
			ft_move_hostiledown(v);
		else if (random == 3)
			ft_move_hostileright(v);
		i = 0;
	}
}

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
		mlx_loop_hook(v.mlx_ptr, ft_frames, &v);
		mlx_loop(v.mlx_ptr);
	}
	return (0);
}
