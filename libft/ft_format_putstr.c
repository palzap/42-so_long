/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:05:34 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:57:25 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_print_width(char *str, t_buffer *values)
{
	int	count;

	count = 0;
	while (values->width > (int)ft_strlen(str))
	{
		count += write(1, " ", 1);
		values->width--;
	}
	count += ft_putstr(str);
	free(str);
	return (count);
}

static int	ft_print_minus_width(char *str, t_buffer *values)
{
	int	count;

	count = 0;
	{
		count += ft_putstr(str);
		while (values->width > (int)ft_strlen(str))
		{
			count += write(1, " ", 1);
			values->width--;
		}
	}
	free(str);
	return (count);
}

int	ft_format_putstr(t_buffer *values, char *str)
{
	int		count;
	char	*aux;

	count = 0;
	if (!str)
		aux = ft_strdup("(null)");
	else
	{
		aux = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!aux)
			return (0);
		ft_strlcpy(aux, str, ft_strlen(str) + 1);
	}
	if (values->point)
		ft_strlcpy(aux, str, values->precision + 1);
	if (values->minus == 1)
		count += ft_print_minus_width(aux, values);
	else
		count += ft_print_width(aux, values);
	return (count);
}
