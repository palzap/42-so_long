/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:54:41 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/13 07:49:30 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	ft_format_putchar(t_buffer *v, char c)
{
	int	count;

	count = 0;
	if (v->minus == 1)
	{
		count += write(1, &c, 1);
		while (v->w > 1)
		{
			count += write(1, " ", 1);
			v->w--;
		}
	}
	else
	{
		while (v->w > 1)
		{
			count += write(1, " ", 1);
			v->w--;
		}
		count += write(1, &c, 1);
	}
	return (count);
}
