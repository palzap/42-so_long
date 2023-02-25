/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:37:46 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/25 01:37:13 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>

# define SIZE 32
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_player
{
	void	*mvup;
	void	*mvdown;
	void	*mvright;
	void	*mvleft;
}	t_player;

typedef struct s_hostile
{
	void	*hup;
	void	*hdown;
	void	*hright;
	void	*hleft;
}	t_hostile;

typedef struct s_values
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	void		*w_img;
	void		*c_img;
	void		*e_img;
	void		*h_img;
	void		*f_img;
	int			map_x;
	int			map_y;
	int			img_x;
	int			img_y;
	int			player_x;
	int			player_y;
	int			p;
	int			c;
	int			e;
	int			h;
	int			i;
	int			j;
	int			moves;
	t_player	pl;
	t_hostile	hostile;
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
/* Checks the map and puts the corresponding image to the window. */
void	ft_load_map2(t_values *v);

/* Checks the map and puts the corresponding image to the window. */
void	ft_load_map(t_values *v);

/* Creates the memory addresses for mlx_ptr, window and all images. */
void	ft_graphics(t_values *v);

/* Checks which movement the player will execute according 
to the button press. */
int		ft_check_move(int keycode, t_values *v);

/*Prints the number of moves on the screen and takes care of animations*/
int		ft_frames(t_values *v);

/*HOSTILE---------------------------------------------------------------------*/
/* Loads all hostile images. */
void	ft_load_hostile(t_values *v);

/* Moves hostiles right. */
void	ft_move_hostileright(t_values *v);

/* Moves hostiles left. */
void	ft_move_hostileleft(t_values *v);

/* Moves hostiles up. */
void	ft_move_hostileup(t_values *v);

/* Moves hostiles down. */
void	ft_move_hostiledown(t_values *v);

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

/*PATH------------------------------------------------------------------------*/
/* Checks if there is a valid path to complete the game. */
int		ft_flood_fill(t_values *v, char **map, int x, int y);

/* Duplicates the **map to apply flood_fill. */
void	ft_check_path(t_values *v);

/*PLAYER----------------------------------------------------------------------*/
/* Loads all player images. */
void	ft_load_player(t_values *v);

/* Moves player right. */
int		ft_move_right(t_values *v, int x, int y);

/* Moves player left. */
int		ft_move_left(t_values *v, int x, int y);

/* Moves player up. */
int		ft_move_up(t_values *v, int x, int y);

/* Moves player down. */
int		ft_move_down(t_values *v, int x, int y);

/*SO_LONG---------------------------------------------------------------------*/
/* Initialize all struct values to 0. */
void	ft_init_struct(t_values *v);

/* Checks if the file exists or is a valid .ber file. */
void	ft_check_file(char *file, t_values *v);

#endif
