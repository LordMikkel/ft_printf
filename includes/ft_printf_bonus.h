/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:32:05 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/17 23:41:47 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

// ------------ Bonus (estructura flags) ------------
typedef struct s_format
{
	int		width;			// Flags '0' y '-' Ancho mínimo (ej: %-10s)
	int		precision;		// Flag '.' Precisión (ej: %.5d)
	int		zero_pad;		// Flag '0' (ej: %05d)
	int		left_align;		// Flag '-' (ej: %-10s)
	int		hash;			// Flag '#' (ej: %#x)
	int		space;			// Flag ' ' (ej: % d)
	int		plus;			// Flag '+' (ej: %+d)
	char	specifier;		// Carácter de conversión (c, s, d, etc.)
}	t_format;

// ------------- Funtion (Principal) ----------------
int		ft_printf(char const *str, ...);

// ----------- Aux. Funtion (flags bonus) ------------
void	ft_apply_flags(char **str, t_format *fmt);
void	ft_apply_hash(char **str, t_format *fmt);
void	ft_apply_left_align(char **str, t_format *fmt);
void	ft_apply_plus(char **str, t_format *fmt);
void	ft_apply_precision(char **str, t_format *fmt);
void	ft_apply_space(char **str, t_format *fmt);
void	ft_apply_zero_pad(char **str, t_format *fmt);
void	ft_apply_min_width(char **str, t_format *fmt);

// ------------ Print Funtion (Utils) ----------------
int		ft_print_char(char c, t_format *fmt);
int		ft_print_str(char *str, t_format *fmt);
int		ft_print_ptr(void *ptr, t_format *fmt);
int		ft_print_num(int n, t_format *fmt);
int		ft_print_unsigned(unsigned int n, t_format *fmt);
int		ft_print_hex(unsigned int n, t_format *fmt, int uppercase);

// ------------ Aux. Funtion (Utils) --------------
char	*ft_itoa_base(long n, char *base);
char	*ft_utoa_base(unsigned long n);

#endif
