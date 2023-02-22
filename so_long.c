/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:34:48 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/22 07:27:41 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"
#include "minilibx-linux/mlx.h"

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
    while (v->map[i++])
        free(v->map[i]);
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
    while (v->i < v->map_y)
    {
        v->j = 1;
        if (v->map[v->i][0] != '1' || v->map[v->i][v->map_x - 1] != '1')
                ft_error(v);
        while (v->j < v->map_x - 1)
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
    v->map_x = ft_strlen(v->map[0]) - 1;
    while (v->map[0][v->j] != '\n')
    {
        if (v->map[0][v->j] != '1')
            ft_error(v);
        v->j++;
    }
    v->j = 0;
    while (v->map[v->map_y - 1][v->j] != '\n')
    {
        if (v->map[v->map_y - 1][v->j] != '1')
            ft_error(v);
        v->j++;
    }
    ft_check_map(v);
}

void    ft_make_map(char *file, t_values *v)
{
    char    *line;
    int fd;
    
    v->map = (char **)malloc(sizeof(char *) * (v->map_y + 1));
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
        v->map_y++;
    }
    ft_printf("%i\n", v->map_y);
    free(line);
    close(fd);
    ft_make_map(file, v);
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
    int x = 0;
    int y = 0;
    t_values    v;

    ft_init_struct(&v);
    if (argc == 2 && argv[1])
        ft_get_y(argv[1], &v);
    v.mlx_ptr = mlx_init ();
    v.win_ptr = mlx_new_window(v.mlx_ptr, (v.map_x * 50), (v.map_y * 50), "so_long");

    v.w_img = mlx_xpm_file_to_image(v.mlx_ptr, "textures/wall.xpm", &v.img_x, &v.img_y);
    v.p_img = mlx_xpm_file_to_image(v.mlx_ptr, "textures/player.xpm", &v.img_x, &v.img_y);
    v.c_img = mlx_xpm_file_to_image(v.mlx_ptr, "textures/collectible.xpm", &v.img_x, &v.img_y);
    v.e_img = mlx_xpm_file_to_image(v.mlx_ptr, "textures/exit.xpm", &v.img_x, &v.img_y);
    v.f_img = mlx_xpm_file_to_image(v.mlx_ptr, "textures/floor.xpm", &v.img_x, &v.img_y);
    while (i < (v.map_y))
    {
        j = 0;
        x = 0;
        while (j < v.map_x)
        {
            if (v.map[i][j] == '1')
            {
                mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.w_img, x, y);
                x += 50;
            }
            else if (v.map[i][j] == 'C')
            {
                mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.c_img, x, y);
                x += 50;
            }
            else if (v.map[i][j] == 'E')
            {
                mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.e_img, x, y);
                x += 50;
            }
            else if (v.map[i][j] == 'P')
            {
                mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.p_img, x, y);
                x += 50;
            }
            else if (v.map[i][j] == '0')
            {
                mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.f_img, x, y);
                x += 50;
            }
            j++;
        }
        y += 50;
        i++;
    }
    mlx_loop(v.mlx_ptr);
    return (0);
}
