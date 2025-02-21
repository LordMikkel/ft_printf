/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:30:57 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/15 15:45:19 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_num(int n)
{
	int		len;
	char	*num_str;

	num_str = ft_itoa(n);
	if (!num_str)
		return (-1);
	len = write(1, num_str, ft_strlen(num_str));
	free(num_str);
	return (len);
}
