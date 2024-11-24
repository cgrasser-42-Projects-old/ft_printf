/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:41:58 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/24 07:06:37 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_putstr(char *s, int len)
{
	if (!s)
		return (write(STD, NULL_STR, len));
	else
		return (write(STD, s, len));
}

static int	handle_string_no_minus(t_flags *flags, char *s, int size_s)
{
	int	len;

	len = 0;
	if (flags->precision < size_s && flags->precision >= 0)
	{
		if (!s && flags->precision <= NULL_LEN)
			return (handle_flag_width(flags->width, len, SPACE));
		else
			return (handle_flag_width(flags->width, flags->precision, SPACE)
				+ ft_putstr(s, flags->precision));
	}
	else
		return (handle_flag_width(flags->width, size_s, SPACE)
			+ ft_putstr(s, size_s));
}

static int	handle_string_minus(t_flags *flags, char *s, int size_s)
{
	int	len;

	len = 0;
	if (flags->precision < size_s && flags->precision >= 0)
	{
		if (!s && flags->precision <= NULL_LEN)
			return (handle_flag_width(flags->width, len, SPACE));
		else
			return (ft_putstr(s, flags->precision)
				+ handle_flag_width(flags->width, flags->precision, SPACE));
	}
	else
		return (ft_putstr(s, size_s)
			+ handle_flag_width(flags->width, size_s, SPACE));
}

int	handle_char(int c, t_flags *flags)
{
	int	len;

	len = 1;
	if (!flags->minus)
		len += handle_flag_width(flags->width, 1, SPACE);
	ft_putchar_fd((char)c, 1);
	if (flags->minus)
		len += handle_flag_width(flags->width, 1, SPACE);
	return (len);
}

int	handle_string(char *s, t_flags *flags)
{
	int	size_s;

	if (!s)
		size_s = NULL_LEN;
	else
		size_s = ft_strlen(s);
	if (flags->minus)
		return (handle_string_minus(flags, s, size_s));
	else
		return (handle_string_no_minus(flags, s, size_s));
}
