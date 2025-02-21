/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_left_align_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:00:49 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/16 00:55:48 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_apply_left_align(char **str, t_format *fmt)
{
	int		len;
	char	*padding;
	char	*new_str;

	len = ft_strlen(*str);
	if (fmt->width > len && fmt->specifier != '%')
	{
		padding = ft_calloc(fmt->width - len + 1, sizeof(char));
		if (!padding)
			return ;
		ft_memset(padding, ' ', fmt->width - len);
		new_str = ft_strjoin(*str, padding);
		free(padding);
		if (!new_str)
		{
			free(*str);
			*str = NULL;
			return ;
		}
		free(*str);
		*str = new_str;
	}
}
