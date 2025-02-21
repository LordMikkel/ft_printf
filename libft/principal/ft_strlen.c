/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:06:24 by migarrid          #+#    #+#             */
/*   Updated: 2025/01/21 21:00:10 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
/*#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 1)
		return (1);
	printf("the string '%s' is composed by %ld characters",
		av[1], ft_strlen(av[1]));
	return (0);
}*/
