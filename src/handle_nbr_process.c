/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nbr_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:36:35 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/24 06:09:23 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	handle_nbr_precision(t_flags *flags, int size_nb,
	int len, char *base)
{
	len += handle_flag_width(flags->width, flags->precision + len, SPACE);
	handle_flag_plus(flags, PRINT);
	handle_flag_hash(flags, base);
	len += handle_flag_width(flags->precision, size_nb, ZERO);
	return (len);
}

static int	handle_nbr_precision_null(t_flags *flags, int len)
{
	if (flags->width > 0)
		return (write(STD, " ", 1) + len);
	else
		return (len);
}

int	handle_nbr_minus(t_flags *flags, unsigned long int nb,
	int size_nb, char *base)
{
	int	len;

	len = 0;
	len += handle_flag_plus(flags, PRINT);
	len += handle_flag_hash(flags, base);
	if (flags->precision > size_nb)
		len += handle_flag_width(flags->precision, size_nb, ZERO);
	if (flags->precision == 0 && nb == 0)
		return (write(STD, " ", 1) + handle_flag_width(flags->width,
				+ (len + 1), SPACE));
	ft_putnbr_base(nb, base);
	len += handle_flag_width(flags->width, size_nb + len, SPACE);
	return (len + size_nb);
}

int	handle_nbr_no_minus(t_flags *flags, unsigned long int nb,
	int size_nb, char *base)
{
	int	len;

	len = 0;
	len += handle_flag_plus(flags, READ);
	len += handle_flag_hash(flags, 0);
	if (flags->precision > size_nb)
	{
		len = handle_nbr_precision(flags, size_nb, len, base);
		return (ft_putnbr_base(nb, base), len + size_nb);
	}
	if (flags->zero && flags->precision == -1)
	{
		handle_flag_plus(flags, PRINT);
		handle_flag_hash(flags, base);
		len += handle_flag_width(flags->width, size_nb + len, ZERO);
	}
	else
	{
		len += handle_flag_width(flags->width, size_nb + len, SPACE);
		handle_flag_plus(flags, PRINT);
		handle_flag_hash(flags, base);
	}
	if (flags->precision == 0 && nb == 0)
		return (handle_nbr_precision_null(flags, len));
	return (ft_putnbr_base(nb, base), len + size_nb);
}
