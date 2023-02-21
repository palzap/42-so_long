/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:37:46 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/17 19:08:43 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"

typedef struct s_values
{
	char	**map;
	int	x;
	int	y;
	int	p;
	int	c;
	int	e;
	int	i;
	int	j;
}	t_values;

void    ft_init_struct(t_values *v);
void	ft_get_y(char *file, t_values *v);
void    ft_make_map(char *file, t_values *v);
void	ft_check_walls(t_values *v);
void    ft_check_map(t_values *v);
void    ft_error(t_values *v);
void    ft_free_map(t_values *v);



#endif
