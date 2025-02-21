/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:32:45 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/14 21:08:39 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_specifiers(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_num(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex
			(va_arg(args, unsigned int), specifier == 'X'));
	else if (specifier == '%')
		return (ft_print_char('%'));
	return (0);
}

static int	ft_format(const char *str, va_list args)
{
	t_format	fmt;

	fmt.specifier = *str;
	return (ft_specifiers(fmt.specifier, args));
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;
	int		result;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			result = ft_format(str, args);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count = count + result;
		}
		else
			count = count + write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
