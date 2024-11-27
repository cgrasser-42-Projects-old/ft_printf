/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:04:53 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/27 12:05:38 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
