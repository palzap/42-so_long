/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:37:46 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/22 12:00:13 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../minilibx-linux/mlx.h"

# define SIZE 50

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
	int	map_x;
	int	map_y;
	int	img_x;
	int img_y;
	int	start_x;
	int	start_y;
	int	p;
	int	c;
	int	e;
	int	h;
	int	i;
	int	j;
}	t_values;

void    ft_init_struct(t_values *v);
void	ft_get_y(char *file, t_values *v);
void    ft_make_map(char *file, t_values *v);
void	ft_check_walls(t_values *v);
void    ft_check_map(t_values *v);
void    ft_error(t_values *v, char *msg);
void    ft_free_map(t_values *v);

#endif
