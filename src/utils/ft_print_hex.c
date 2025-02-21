/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:31:00 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/17 19:20:59 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_hex(unsigned int n, int uppercase)
{
	int		len;
	char	*base;
	char	*num_str;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	num_str = ft_itoa_base((long)n, base);
	if (!num_str)
		return (-1);
	len = write(1, num_str, ft_strlen(num_str));
	free(num_str);
	return (len);
}
