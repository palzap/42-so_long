/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_puthexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:59:53 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:57:07 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_p0(char *hexastr, t_buffer *values, int precision, char base)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(hexastr);
	if (values->hash)
		len += 2;
	if (values->width && values->precision)
	{
		while ((values->width--) > precision + len)
			count += write(1, " ", 1);
		if (values->hash && hexastr[0] != '0')
		{
			count += write(1, "0", 1);
			count += ft_putchar(base + 23);
		}
		while ((values->precision--) > len)
			count += write(1, "0", 1);
	}
	else
		count += ft_phexa01(hexastr, values, len, base);
	count += ft_putstr(hexastr);
	return (count);
}

static int	ft_pw(char *hexastr, t_buffer *values, int precision, char base)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(hexastr);
	if (values->hash && hexastr[0] != '0')
		len += 2;
	if (values->width && values->precision)
	{
		while ((values->width--) > precision)
			count += write(1, " ", 1);
		if (values->hash && hexastr[0] != '0')
		{
			count += write(1, "0", 1);
			count += ft_putchar(base + 23);
		}
		while ((values->precision--) > (int)ft_strlen(hexastr))
			count += write(1, "0", 1);
	}
	else
		count += ft_phexaw1(hexastr, values, len, base);
	count += ft_putstr(hexastr);
	return (count);
}

static int	ft_pmw(char *hexastr, t_buffer *values, int precision, char base)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(hexastr);
	if (values->hash && hexastr[0] != '0')
	{
			count += write(1, "0", 1);
			count += ft_putchar(base + 23);
			len += 2;
			precision += 2;
	}
	if (values->width && values->precision)
	{
		while ((values->precision--) > (int)ft_strlen(hexastr))
			count += write(1, "0", 1);
		count += ft_putstr(hexastr);
		while ((values->width--) > precision)
			count += write(1, " ", 1);
	}
	else
		count += ft_phexamw1(hexastr, values, len);
	return (count);
}

int	ft_format_puthexa(t_buffer *values, unsigned long long nb)
{
	int		count;
	char	*hexastr;
	char	*base;
	int		precision;

	count = 0;
	if (values->conversion_type == 'x')
		base = "0123456789abcdef";
	if (values->conversion_type == 'X')
		base = "0123456789ABCDEF";
	hexastr = ft_get_hexastr(nb, base);
	precision = values->precision;
	if (values->minus)
		count += ft_pmw(hexastr, values, precision, base[10]);
	else if (values->zero)
		count += ft_p0(hexastr, values, precision, base[10]);
	else
		count += ft_pw(hexastr, values, precision, base[10]);
	free(hexastr);
	return (count);
}
