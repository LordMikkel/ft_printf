/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:30:46 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/15 18:34:44 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_str(char *str)
{
	int		len;

	if (!str)
	{
		len = write(1, "(null)", 6);
		return (len);
	}
	len = write(1, str, ft_strlen(str));
	return (len);
}
