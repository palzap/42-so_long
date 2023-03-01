/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:37:46 by pealexan          #+#    #+#             */
/*   Updated: 2023/03/01 08:05:34 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>

# define SIZE 50
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define MAPELEMENTS "01CPE"

typedef struct s_values
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	void	*w_img;
	void	*p_img;
	void	*c_img;
	void	*e_img;
	void	*h_img;
	void	*f_img;
	int		map_x;
	int		map_y;
	int		img_x;
	int		img_y;
	int		player_x;
	int		player_y;
	int		p;
	int		c;
	int		e;
	int		h;
	int		i;
	int		j;
	int		moves;
}	t_values;

/*FREE------------------------------------------------------------------------*/

/* Clears all allocated memory and exits. */
int		ft_exit(t_values *v);

/* Clears all memory allocated for all images. */
void	ft_destroy_images(t_values *v);

/* Frees **map, prints an error message and exits. */
void	ft_error(t_values *v, char *msg);

/* Frees **map. */
void	ft_free_map(t_values *v);

/*GRAPHICS--------------------------------------------------------------------*/

/* Loads images and checks if memory was correctly allocated. */
void	*ft_load_image(t_values *v, char *path);

/* Checks the map and puts the corresponding image to the window. */
void	ft_load_map(t_values *v);

/* Creates the memory addresses for mlx_ptr, window and all images. */
void	ft_graphics(t_values *v);

/* Moves the player accordingly to the pressed button. */
int		ft_move_player(t_values *v, int x, int y);

/* Checks which movement the player will execute according 
to the button press. */
int		ft_check_move(int keycode, t_values *v);

/*MAP-------------------------------------------------------------------------*/
/* Checks and outputs the error message. */
void	ft_check_errors(t_values *v);

/* Checks the map and outputs the number of collectibles, players and exits.
Also checks if the side walls are ok. */
void	ft_check_map(t_values *v);

/* Checks top and bottom walls and also if the map is rectangular. */
void	ft_check_walls(t_values *v);

/* Creates **map by using get_next_line on the map file. */
void	ft_make_map(char *file, t_values *v);

/* Checks how many lines there are on the map file. */
void	ft_get_x_y(char *file, t_values *v);

/*MAP-------------------------------------------------------------------------*/
/* Checks if there is a valid path to complete the game. */
int		ft_flood_fill(t_values *v, char **map, int x, int y);

/* Duplicates the **map to apply flood_fill. */
void	ft_check_path(t_values *v);

/*SO_LONG---------------------------------------------------------------------*/
/* Initialize all struct values to 0. */
void	ft_init_struct(t_values *v);

/* Checks if the file exists or is a valid .ber file. */
void	ft_check_file(char *file, t_values *v);

#endif
