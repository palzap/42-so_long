/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:34:48 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/23 07:23:41 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

/* 11111111111111111111
1C0000000000000000C1
10000000000000000001
10000000000000000001
10000000000000000001
1P0000000000000000E1
11111111111111111111

void    ft_destroy_all(t_values *v)
{
    ft_free_map(v);
    mlx_destroy_image(v->w_img);
    mlx_destroy_image(v->p_img);
    mlx_destroy_image(v->e_img);
    mlx_destroy_image(v->h_img);
    mlx_destroy_image(v->c_img);
    mlx_destroy_window(v->win_ptr);
}

void    ft_move_up(t_values *v)
{
    y--;
    if (map[x][y] == '0')
    {
        mlx_destroy_image(v->p_img);
        mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->p_img, x * 50, y * 50);
    }
    else if (map[x][y] == 'C')
    {
        mlx_destroy_image(v->p_img);
        mlx_destroy_image(v->c_img);
        v->c--;
        mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->p_img, x * 50, y * 50);
    }
    else if (map[x][y] == 'H' || (map[x][y] == 'E' && !v->c))
    {
        ft_destroy_all(v);
        mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->p_img, x * 50, y * 50);
    }
    else
        return ;
    moves++;
} */

void    ft_free_map(t_values *v)
{
    int i;

    i = 0;
    while (v->map[i])
        free(v->map[i++]);
    free(v->map);
}

void    ft_error(t_values *v, char *msg)
{
    ft_free_map(v);
    ft_putstr_fd(msg, 2);
    exit(1);
}

int    ft_flood_fill(t_values *v, char **map, int x, int y)
{
    static int  collectibles;
    static int  i;

    if (map[y][x] == '1')
        return (0);
    else if (map[y][x] == 'C')
        collectibles++;
    else if (map[y][x] == 'E')
        i = 1;
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
    if (ft_flood_fill(v, map_copy, v->start_x, v->start_y) != 1)
    {
        ft_free_split(map_copy);
        ft_error(v, "Error\nNo valid path\n");
    }
    ft_free_split(map_copy);
}

void    ft_check_errors(t_values *v)
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

void    ft_check_map(t_values *v)
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
                v->start_x = v->j;
                v->start_y = v->i;
                v->p++;
            }
            v->j++;
        }
        v->i++;
    }
    ft_check_errors(v);
}

void    ft_check_walls(t_values *v)
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

void    ft_make_map(char *file, t_values *v)
{
    char    *line;
    int fd;
    
    v->map = (char **)malloc(sizeof(char *) * (v->map_y + 1));
    if (!v->map)
        ft_error(v, "Error\nCouldn't allocate memory\n");
    fd = open(file, O_RDONLY);
    line = ft_strdup("");
    v->i = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        v->map[v->i] = ft_strtrim(line, "\n");
        free(line);
        v->i++;
    }
    free(line);
    v->map[v->i] = 0;
    ft_check_walls(v);
}

void ft_get_x_y(char *file, t_values *v)
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
        v->map_y++;
    }
    free(line);
    close(fd);
    ft_make_map(file, v);
}

void    ft_check_file(char *file, t_values *v)
{
    int fd;

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

void    ft_init_struct(t_values *v)
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
    v->start_x = 0;
	v->start_y = 0;
	v->p = 0;
	v->c = 0;
	v->e = 0;
	v->h = 0;
    v->i = 0;
    v->j = 0;
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    //int fd;
    t_values    v;

    ft_init_struct(&v);
    if (argc == 2)
    {
        ft_check_file(argv[1], &v);
        //ft_graphics(v);
        v.mlx_ptr = mlx_init ();
        v.win_ptr = mlx_new_window(v.mlx_ptr, (v.map_x * SIZE), (v.map_y * SIZE), "so_long");
        v.w_img = mlx_xpm_file_to_image(v.mlx_ptr, "textures/wall.xpm", &v.img_x, &v.img_y);
        v.p_img = mlx_xpm_file_to_image(v.mlx_ptr, "textures/player.xpm", &v.img_x, &v.img_y);
        v.c_img = mlx_xpm_file_to_image(v.mlx_ptr, "textures/collectible.xpm", &v.img_x, &v.img_y);
        v.e_img = mlx_xpm_file_to_image(v.mlx_ptr, "textures/exit.xpm", &v.img_x, &v.img_y);
        v.f_img = mlx_xpm_file_to_image(v.mlx_ptr, "textures/floor.xpm", &v.img_x, &v.img_y);
        while (i < (v.map_y))
        {
            j = 0;
            while (j < v.map_x)
            {
                if (v.map[i][j] == '1')
                    mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.w_img, j * SIZE, i *  SIZE);
                else if (v.map[i][j] == 'C')
                    mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.c_img, j * SIZE, i * SIZE);
                else if (v.map[i][j] == 'E')
                    mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.e_img, j * SIZE, i * SIZE);
                else if (v.map[i][j] == 'P')
                    mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.p_img, j * SIZE, i * SIZE);
                j++;
            }
            i++;
        }
        mlx_loop(v.mlx_ptr);
    }
    return (0);
}
