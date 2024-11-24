/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:01:30 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/24 07:16:57 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*

	The ft_printf function is used to display information on the screen.
	It allows you to print strings, variables, or other data types 
	with precise formatting.

	Here is the general structure of the function:

	ft_printf("format", arguments);

	- "format": A string that contains text and format specifiers.
	These format specifiers begin with % and are replaced by the values
	of the arguments provided in arguments.
	- arguments: The values to be displayed, which correspond to the format
	specifiers in the string. For example, an integer for %d,
	a string for %s, etc.

*/

static void	handle_flag_digit(t_flags *flags, const char *s, int *i)
{
	if (flags->star)
		flags->width = 0;
	while (ft_isdigit(s[*i]))
		flags->width = flags->width * 10 + (s[(*i)++] - '0');
}

static void	handle_flag_star(va_list args, t_flags *flags)
{
	flags->star = 1;
	if (flags->precision == 0)
	{
		flags->precision = va_arg(args, int);
		if (flags->precision < 0)
			flags->precision = -1;
	}
	else
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
	}
}

static void	handle_flags(va_list args, const char *s, t_flags *flags, int *i)
{
	if (s[*i] == '+')
		flags->plus = 1;
	if (s[*i] == '-')
		flags->minus = 1;
	if (s[*i] == '#')
		flags->hash = 1;
	if (s[*i] == '0')
		flags->zero = 1;
	if (s[*i] == ' ')
		flags->space = 1;
	if (s[*i] == '*')
		handle_flag_star(args, flags);
	if (s[*i] == '.')
	{
		(*i)++;
		flags->precision = 0;
		while (ft_isdigit(s[*i]))
			flags->precision = flags->precision * 10 + (s[(*i)++] - '0');
	}
	else if (ft_isdigit(s[*i]))
		handle_flag_digit(flags, s, i);
	else
		(*i)++;
}

static int	handle_format(va_list args, char format, t_flags *flags)
{
	if (format == 'c')
		return (handle_char(va_arg(args, int), flags));
	if (format == 's')
		return (handle_string(va_arg(args, char *), flags));
	if (format == 'p')
		return (handle_pointer((unsigned long int)va_arg(args, void *), flags));
	if (format == 'd' || format == 'i')
		return (handle_integer(va_arg(args, int), flags));
	if (format == 'u')
		return (handle_unsigned_int(va_arg(args, unsigned int), flags));
	if (format == 'x')
		return (handle_hexadecimal(va_arg(args, unsigned long), flags, HEX));
	if (format == 'X')
		return (handle_hexadecimal(va_arg(args, unsigned long), flags, HEXA));
	if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_flags	*flags;
	int		len;
	int		i;

	len = 0;
	i = 0;
	flags = ft_flagsnew();
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			while (ft_strchr("+- *.0#", s[i]) || ft_isdigit(s[i]))
				handle_flags(args, s, flags, &i);
			len += handle_format(args, s[i], flags);
			ft_flags_clear(flags);
		}
		else
			len += handle_char(s[i], flags);
		i++;
	}
	return (free(flags), va_end(args), len);
}
