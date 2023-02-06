/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_putunsignnbr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:59:53 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:57:28 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_print_zeroes(char *number, t_buffer *values, int precision)
{
	int	count;

	count = 0;
	if (values->width && values->precision)
	{
		while ((values->width--) > precision + (int)ft_strlen(number))
			count += write(1, " ", 1);
		while ((values->precision--) > (int)ft_strlen(number))
			count += write(1, "0", 1);
	}
	else
	{
		while ((values->width--) > (int)ft_strlen(number))
			count += write(1, "0", 1);
		while ((values->precision--) > (int)ft_strlen(number))
			count += write(1, "0", 1);
	}
	count += ft_putstr(number);
	return (count);
}

static int	ft_print_width(char *number, t_buffer *values, int precision)
{
	int	count;

	count = 0;
	if (values->width && values->precision)
	{
		while ((values->width--) > precision)
			count += write(1, " ", 1);
		while ((values->precision--) > (int)ft_strlen(number))
			count += write(1, "0", 1);
	}
	else
	{
		while ((values->width--) > (int)ft_strlen(number))
			count += write(1, " ", 1);
		while ((values->precision--) > (int)ft_strlen(number))
			count += write(1, "0", 1);
	}
	count += ft_putstr(number);
	return (count);
}

static int	ft_print_minus_width(char *number, t_buffer *values, int precision)
{
	int	count;

	count = 0;
	if (values->width && values->precision)
	{
		while ((values->precision--) > (int)ft_strlen(number))
			count += write(1, "0", 1);
		count += ft_putstr(number);
		while ((values->width--) > precision)
			count += write(1, " ", 1);
	}
	else
	{
		while ((values->precision--) > (int)ft_strlen(number))
			count += write(1, "0", 1);
		count += ft_putstr(number);
		while ((values->width--) > (int)ft_strlen(number))
			count += write(1, " ", 1);
	}
	return (count);
}

int	ft_format_putunsignnbr(t_buffer *values, unsigned long long nb)
{
	int		count;
	char	*number;
	int		precision;

	count = 0;
	number = ft_utoa(nb);
	precision = values->precision;
	if (values->minus)
		count += ft_print_minus_width(number, values, precision);
	else if (values->zero)
		count += ft_print_zeroes(number, values, precision);
	else
		count += ft_print_width(number, values, precision);
	free(number);
	return (count);
}
