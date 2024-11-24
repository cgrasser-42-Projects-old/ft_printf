/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:36:14 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/24 06:09:51 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_nbrlen_base(unsigned long int n, int base_len)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

static void	ft_putnbr_recur_base(unsigned long int nb, char *base, int base_len)
{
	if (nb >= (unsigned long int)base_len)
	{
		ft_putnbr_recur_base(nb / base_len, base, base_len);
		ft_putnbr_recur_base(nb % base_len, base, base_len);
	}
	else
		ft_putchar_fd(base[nb], STD);
}

void	ft_putnbr_base(unsigned long int nb, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	ft_putnbr_recur_base(nb, base, base_len);
}
