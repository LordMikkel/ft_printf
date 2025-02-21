/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:30:53 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/17 23:45:14 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int				len;
	char			*num_str;
	char			*tmp;
	uintptr_t		address;

	if (!ptr)
	{
		len = write(1, "(nil)", 5);
		return (len);
	}
	address = (uintptr_t)ptr;
	tmp = ft_utoa_base(address);
	if (!tmp)
		return (-1);
	num_str = ft_strjoin("0x", tmp);
	free(tmp);
	if (!num_str)
		return (-1);
	len = write(1, num_str, ft_strlen(num_str));
	free(num_str);
	return (len);
}
