/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:34:48 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/18 17:04:25 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"
#include "minilibx-linux/mlx.h"

void    ft_free_map(t_values *v)
{
    v->i = 0;
    while (v->map[v->i++])
        free(v->map[v->i]);
    free(v->map);
}

void    ft_error(t_values *v)
{
    ft_free_map(v);
    write(2, "Error\n", 6);
    exit(1);
}

void    ft_check_map(t_values *v)
{
    v->i = 1;
    while (v->i < v->y)
    {
        v->j = 1;
        if (v->map[v->i][0] != '1' || v->map[v->i][v->x - 1] != '1')
                ft_error(v);
        while (v->j < v->x - 1)
        {
            if (v->map[v->i][v->j] == 'C')
                v->c++;
            if (v->map[v->i][v->j] == 'E')
                v->e++;
            if (v->map[v->i][v->j] == 'P')
                v->p++;
            v->j++;
        }
        v->i++;
    }
    if (v->c == 0)
        ft_error(v);
    if (v->e != 1)
        ft_error(v);
    if (v->p != 1)
        ft_error(v);
}

void    ft_check_walls(t_values *v)
{
    v->j = 0;        
    v->x = ft_strlen(v->map[0]) - 1;
    ft_printf("%i\n", v->x);
    while (v->map[0][v->j] != '\n')
    {
        if (v->map[0][v->j] != '1')
            ft_error(v);
        v->j++;
    }
    v->j = 0;
    while (v->map[v->y - 1][v->j] != '\n')
    {
        if (v->map[v->y - 1][v->j] != '1')
            ft_error(v);
        v->j++;
    }
    ft_check_map(v);
}

void    ft_make_map(char *file, t_values *v)
{
    char    *line;
    int fd;
    
    v->map = (char **)malloc(sizeof(char *) * (v->y + 1));
    fd = open(file, O_RDONLY);
    line = ft_strdup("");
    v->i = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        v->map[v->i] = ft_strdup(line);
        ft_printf("%s", v->map[v->i]);
        free(line);
        v->i++;
    }
    free(line);
    v->map[v->i] = '\0';
    ft_check_walls(v);
}

void ft_get_y(char *file, t_values *v)
{
    char    *line;
    int fd;

    fd = open(file, O_RDONLY);
    line = ft_strdup("");
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        free(line);
        v->y++;
    }
    ft_printf("%i\n", v->y);
    free(line);
    close(fd);
    ft_make_map(file, v);
}

void    ft_init_struct(t_values *v)
{
    v->map = 0;
    v->x = 0;
    v->y = 0;
    v->p = 0;
    v->c = 0;
    v->e = 0;
    v->i = 0;
    v->j = 0;
}

int main(int argc, char **argv)
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *wall_ptr;
    int wall_x;
    int wall_y;
    void    *player_ptr;
    int player_x;
    int player_y;
    void    *collectible_ptr;
    int collectible_x;
    int collectible_y;
    void    *exit_ptr;
    int exit_x;
    int exit_y;
    void    *floor_ptr;
    int floor_x;
    int floor_y;
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    t_values    values;

/*     (void)values;
    (void)argc;
    (void)argv; */
    ft_init_struct(&values);
    if (argc == 2 && argv[1])
        ft_get_y(argv[1], &values);
    mlx_ptr = mlx_init ();
    win_ptr = mlx_new_window(mlx_ptr, (values.x * 50), (values.y * 50), "so_long");
    wall_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/wall.xpm", &wall_x, &wall_y);
    player_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/player.xpm", &player_x, &player_y);
    collectible_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/collectible.xpm", &collectible_x, &collectible_y);
    exit_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/exit.xpm", &exit_x, &exit_y);
    floor_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/floor.xpm", &floor_x, &floor_y);
    while (i < (values.y))
    {
        j = 0;
        x = 0;
        while (j < values.x)
        {
            if (values.map[i][j] == '1')
            {
                mlx_put_image_to_window(mlx_ptr, win_ptr, wall_ptr, x, y);
                x += 50;
            }
            else if (values.map[i][j] == 'C')
            {
                mlx_put_image_to_window(mlx_ptr, win_ptr, collectible_ptr, x, y);
                x += 50;
            }
            else if (values.map[i][j] == 'E')
            {
                mlx_put_image_to_window(mlx_ptr, win_ptr, exit_ptr, x, y);
                x += 50;
            }
            else if (values.map[i][j] == 'P')
            {
                mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr, x, y);
                x += 50;
            }
            else if (values.map[i][j] == '0')
            {
                mlx_put_image_to_window(mlx_ptr, win_ptr, floor_ptr, x, y);
                x += 50;
            }
            j++;
        }
        y += 50;
        i++;
    }
     mlx_loop(mlx_ptr);
    return (0);
}
