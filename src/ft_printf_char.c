/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:59:41 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/27 12:01:05 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
