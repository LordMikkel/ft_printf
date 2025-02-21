/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:10:56 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/17 19:21:04 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num_str;

	num_str = ft_itoa_base((long)n, "0123456789");
	if (!num_str)
		return (-1);
	len = write(1, num_str, ft_strlen(num_str));
	free(num_str);
	return (len);
}
