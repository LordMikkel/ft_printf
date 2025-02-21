/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:32:05 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/17 23:41:52 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

// ------------ specifier (estructura) ------------
typedef struct s_format
{
	char	specifier;		// Carácter de conversión (c, s, d, etc.)
}	t_format;

// ------------- Funtion (Principal) ----------------
int		ft_printf(char const *str, ...);

// ------------ Print Funtion (Utils) ---------------
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_ptr(void *ptr);
int		ft_print_num(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, int uppercase);

// ------------ Aux. Funtion (Utils) --------------
char	*ft_itoa_base(long n, char *base);
char	*ft_utoa_base(unsigned long n);

#endif
