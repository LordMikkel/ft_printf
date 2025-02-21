/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hash_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:19:56 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/15 15:11:55 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_apply_hash(char **str, t_format *fmt)
{
	char	*prefix;
	char	*new_str;

	if (fmt->hash && (fmt->specifier == 'x' || fmt->specifier == 'X'))
	{
		if (fmt->specifier == 'X')
			prefix = "0X";
		else
			prefix = "0x";
		if ((*str)[0] != '0' || ((*str)[1] != 'x' && (*str)[1] != 'X'))
		{
			new_str = ft_strjoin(prefix, *str);
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
}
