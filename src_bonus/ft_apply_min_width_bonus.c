/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_min_width_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:14:26 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/17 23:30:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_apply_min_width(char **str, t_format *fmt)
{
	char	*new_str;
	int		len;
	char	padding;

	len = ft_strlen(*str);
	if (fmt->width <= len)
		return ;
	padding = ' ';
	if (fmt->zero_pad && !fmt->left_align && fmt->precision == -1)
		padding = '0';
	new_str = (char *)malloc(fmt->width + 1);
	if (!new_str)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	ft_memset(new_str, padding, fmt->width);
	new_str[fmt->width] = '\0';
	if (fmt->left_align)
		ft_memcpy(new_str, *str, len);
	else
		ft_memcpy(new_str + (fmt->width - len), *str, len);
	free(*str);
	*str = new_str;
}
