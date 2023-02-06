/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:34:48 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/06 16:45:11 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"
#include "minilibx-linux/mlx.h"

void	ft_check_map(char *map)
{
	int	map_fd;
	char	*line;

	map_fd = open(map);
	line = ft_strdup("");
	while (line)
	{
		ft_check_line(line);
		free (line);
		line = get_next_line(map_fd);
	}
	free (line);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*mlx_win;
	int	i;

	i = 0;
	if (argc == 2)
		ft_check_map(argv[1]);
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "so_long");
	mlx_loop(mlx_ptr);
	return (0);
}