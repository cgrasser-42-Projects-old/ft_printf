/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 08:14:20 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/24 07:50:07 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define HEXA "0123456789ABCDEF"
# define HEX "0123456789abcdef"
# define HEX_LEN 16
# define DECIMAL "0123456789"
# define DEC_LEN 10
# define NULL_STR "(null)"
# define NULL_LEN 6
# define NIL_PTR "(nil)"
# define NIL_LEN 5
# define STD 1
# define PRINT 1
# define READ 0
# define SPACE ' '
# define ZERO '0'

//=====================================================================| FLAGS |

typedef struct s_flags
{
	int		plus;
	int		minus;
	int		hash;
	int		zero;
	int		space;
	int		precision;
	int		width;
	int		star;
	int		negative;
}	t_flags;

t_flags	*ft_flagsnew(void);
void	ft_flags_clear(t_flags *flags);

//==============================================================| HANDLE FLAGS |

int		handle_flag_plus(t_flags *flags, int option);
int		handle_flag_width(int width, int size_str, char c);
int		handle_flag_hash(t_flags *flags, char *base);

//====================================================================| PRINTF |

int		ft_printf(const char *s, ...);

//=============================================================| HANDLE FORMAT |

int		handle_char(int value, t_flags *flags);
int		handle_string(char *s, t_flags *flags);
int		handle_pointer(unsigned long int ptr, t_flags *flags);
int		handle_integer(int value, t_flags *flags);
int		handle_unsigned_int(unsigned int n, t_flags *flags);
int		handle_hexadecimal(unsigned int hex, t_flags *flags, char *base);

int		handle_nbr_minus(t_flags *flags, unsigned long int nb,
			int size_nb, char *base);
int		handle_nbr_no_minus(t_flags *flags, unsigned long int nb,
			int size_nb, char *base);

//=====================================================================| UTILS |

void	ft_putnbr_base(unsigned long int nb, char *base);
int		ft_nbrlen_base(unsigned long int nb, int base_len);

#endif
