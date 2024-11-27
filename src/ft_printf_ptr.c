/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:07:29 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/27 12:15:43 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putptr(unsigned long int ptr, int size_p)
{
	if (!ptr)
		return (write(STD, NIL_PTR, size_p));
	else
		return (ft_putstr_fd("0x", STD), ft_putnbr_base(ptr, HEX), size_p);
}

int	handle_pointer(unsigned long int ptr, t_flags *flags)
{
	int		size_p;

	if (!ptr)
		size_p = NIL_LEN;
	else
		size_p = 2 + ft_nbrlen_base(ptr, HEX_LEN);
	if (flags->minus)
		return (ft_putptr(ptr, size_p)
			+ handle_flag_width(flags->width, size_p, SPACE));
	else
		return (handle_flag_width(flags->width, size_p, SPACE)
			+ ft_putptr(ptr, size_p));
}
