/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:54:51 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/24 23:23:37 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	ft_check_errors(t_values *v)
	{
	if (v->c == 0)
		ft_error(v, "Error\nNo Collectibles\n");
	else if (v->e == 0)
		ft_error(v, "Error\nNo Exit\n");
	else if (v->p == 0)
		ft_error(v, "Error\nNo Starting position\n");
	else if (v->e > 1)
		ft_error(v, "Error\nMore than 1 Exit\n");
	else if (v->p > 1)
		ft_error(v, "Error\nMore than 1 Starting position\n");
	ft_check_path(v);
}

void	ft_check_map(t_values *v)
{
	v->i = 1;
	while (v->i < v->map_y)
	{
		v->j = 1;
		if (v->map[v->i][0] != '1' || v->map[v->i][v->map_x - 1] != '1')
			ft_error(v, "Error\nInvalid walls\n");
		while (v->map[v->i][v->j])
		{
			if (v->map[v->i][v->j] == 'C')
				v->c++;
			if (v->map[v->i][v->j] == 'E')
				v->e++;
			if (v->map[v->i][v->j] == 'P')
			{
				v->player_x = v->j;
				v->player_y = v->i;
				v->p++;
			}
			v->j++;
		}
		v->i++;
	}
	ft_check_errors(v);
}

void	ft_check_walls(t_values *v)
{
	v->j = 0;
	v->map_x = ft_strlen(v->map[0]);
	while (v->map[0][v->j])
	{
		if (v->map[0][v->j] != '1')
			ft_error(v, "Error\nInvalid walls\n");
		v->j++;
	}
	v->j = 0;
	while (v->map[v->map_y - 1][v->j])
	{
		if (v->map[v->map_y - 1][v->j] != '1')
			ft_error(v, "Error\nInvalid walls\n");
		v->j++;
	}
	v->j = 0;
	while (v->j < v->map_y)
	{
		if (v->map_x != (int)ft_strlen(v->map[v->j]))
			ft_error(v, "Error\nNot rectangular\n");
		v->j++;
	}
	ft_check_map(v);
}

void	ft_make_map(char *file, t_values *v)
{
	char	*line;
	int		fd;

	v->map = (char **)malloc(sizeof(char *) * (v->map_y + 1));
	if (!v->map)
		ft_error(v, "Error\nCouldn't allocate memory\n");
	fd = open(file, O_RDONLY);
	v->i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		v->map[v->i] = ft_strtrim(line, "\n");
		free(line);
		v->i++;
	}
	free(line);
	v->map[v->i] = 0;
	ft_check_walls(v);
}

void	ft_get_x_y(char *file, t_values *v)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		v->map_y++;
	}
	free(line);
	close(fd);
	ft_make_map(file, v);
}
