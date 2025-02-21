/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:20:50 by migarrid          #+#    #+#             */
/*   Updated: 2025/01/21 20:58:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	buffer[1024];
	size_t	i;

	if(ac == 3)
	{
		strlcpy(buffer, av[1], sizeof(buffer));
		printf("Before ft_bzero: %s\n", buffer);
		ft_bzero(buffer, (size_t)atoi(av[2]));
		i = 0;
		printf("After ft_bzero: ");
		while (i < strlen(av[1]))
		{
			printf("%c", buffer[i]);
			i++;
		}
		printf("\n");
		return (0);
	}
	return (1);
}*/
