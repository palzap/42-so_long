/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_puthexa2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:12:06 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:57:09 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_phexamw1(char *hexastr, t_buffer *values, int len)
{
	int	count;

	count = 0;
	while ((values->precision--) > len)
		count += write(1, "0", 1);
	count += ft_putstr(hexastr);
	while ((values->width--) > len)
		count += write(1, " ", 1);
	return (count);
}

int	ft_phexaw1(char *hexastr, t_buffer *values, int len, char base)
{
	int	count;

	count = 0;
	while ((values->width--) > len)
		count += write(1, " ", 1);
	if (values->hash && hexastr[0] != '0')
	{
		count += write(1, "0", 1);
		count += ft_putchar(base + 23);
	}
	while ((values->precision--) > (int)ft_strlen(hexastr))
		count += write(1, "0", 1);
	return (count);
}

int	ft_phexa01(char *hexastr, t_buffer *values, int len, char base)
{
	int	count;

	count = 0;
	if (values->hash && hexastr[0] != '0')
	{
		count += write(1, "0", 1);
		count += ft_putchar(base + 23);
	}
	while ((values->width--) > len)
		count += write(1, "0", 1);
	while ((values->precision--) > len)
		count += write(1, "0", 1);
	return (count);
}
