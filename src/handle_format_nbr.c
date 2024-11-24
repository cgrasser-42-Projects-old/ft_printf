/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:38:12 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/24 06:07:40 by cgrasser         ###   ########.fr       */
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

int	handle_integer(int n, t_flags *flags)
{
	unsigned long int	nb;
	int					size_nb;

	if (n < 0)
	{
		flags->negative = 1;
		if (n == -2147483648)
			nb = 2147483648;
		else
			nb = -n;
	}
	else
		nb = n;
	flags->hash = 0;
	size_nb = ft_nbrlen_base(nb, DEC_LEN);
	if (flags->minus)
		return (handle_nbr_minus(flags, nb, size_nb, DECIMAL));
	else
		return (handle_nbr_no_minus(flags, nb, size_nb, DECIMAL));
}

int	handle_unsigned_int(unsigned int n, t_flags *flags)
{
	unsigned long int	nb;
	int					size_nb;

	nb = n;
	size_nb = ft_nbrlen_base(nb, DEC_LEN);
	flags->hash = 0;
	if (flags->minus)
		return (handle_nbr_minus(flags, nb, size_nb, DECIMAL));
	else
		return (handle_nbr_no_minus(flags, nb, size_nb, DECIMAL));
}

int	handle_hexadecimal(unsigned int hex, t_flags *flags, char *base)
{
	unsigned long int	nb;
	int					size_nb;

	nb = hex;
	if (!nb)
		flags->hash = 0;
	size_nb = ft_nbrlen_base(nb, HEX_LEN);
	if (flags->minus)
		return (handle_nbr_minus(flags, nb, size_nb, base));
	else
		return (handle_nbr_no_minus(flags, nb, size_nb, base));
}
