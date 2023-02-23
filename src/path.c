/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:00:06 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/23 15:00:26 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int    ft_flood_fill(t_values *v, char **map, int x, int y)
{
    static int  collectibles;
    static int  i;

    if (map[y][x] == '1')
        return (0);
    else if (map[y][x] == 'C')
        collectibles++;
    else if (map[y][x] == 'E')
    {
        i = 1;
        return (0);
    }
    if (map[y][x] != 'E')
        map[y][x] = '1';
    ft_flood_fill(v, map, x + 1, y);
    ft_flood_fill(v, map, x - 1, y);
    ft_flood_fill(v, map, x, y + 1);
    ft_flood_fill(v, map, x, y - 1);
    if (collectibles == v->c && i == 1)
        return (1);
    else
        return (0);
} 

void    ft_check_path(t_values *v)
{
    char    **map_copy;

    v->i = 0;
    map_copy = (char **)malloc(sizeof(char *) * (v->map_y + 1));
    if (!map_copy)
        ft_error(v, "Error\nCouldn't allocate memory\n");
    while (v->map[v->i])
    {
        map_copy[v->i] = ft_strdup(v->map[v->i]);
        v->i++;
    }
    map_copy[v->i] = 0;
    if (ft_flood_fill(v, map_copy, v->player_x, v->player_y) != 1)
    {
        ft_free_split(map_copy);
        ft_error(v, "Error\nNo valid path\n");
    }
    ft_free_split(map_copy);
}