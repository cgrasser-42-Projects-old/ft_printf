/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:09:32 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/27 12:10:34 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_flags	*ft_flagsnew(void)
{
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	ft_flags_clear(flags);
	return (flags);
}

void	ft_flags_clear(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->precision = -1;
	flags->width = 0;
	flags->star = 0;
	flags->negative = 0;
}

int	handle_flag_plus(t_flags *flags, int option)
{
	if (flags->negative && option == PRINT)
		return (ft_putchar_fd('-', STD), 1);
	if (flags->plus && option == PRINT)
		return (ft_putchar_fd('+', STD), 1);
	if (flags->space && option == PRINT)
		return (ft_putchar_fd(' ', STD), 1);
	if (flags->negative || flags->plus || flags->space)
		return (1);
	return (0);
}

int	handle_flag_width(int width, int size_str, char c)
{
	int	len;

	len = 0;
	while (width - size_str > 0)
	{
		ft_putchar_fd(c, STD);
		width--;
		len++;
	}
	return (len);
}

int	handle_flag_hash(t_flags *flags, char *base)
{
	if (flags->hash)
	{
		if (!base)
			return (2);
		if (ft_memcmp(base, HEXA, HEX_LEN) == 0)
			return (write(STD, "0X", 2));
		if (ft_memcmp(base, HEX, HEX_LEN) == 0)
			return (write(STD, "0x", 2));
	}
	return (0);
}
