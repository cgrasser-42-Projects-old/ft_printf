/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:06:00 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/27 12:07:08 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
