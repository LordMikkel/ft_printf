/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_plus_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:14:53 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/16 00:32:23 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_apply_plus(char **str, t_format *fmt)
{
	char	*new_str;

	if (fmt->plus && (*str)[0] != '-')
	{
		new_str = ft_strjoin("+", *str);
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
