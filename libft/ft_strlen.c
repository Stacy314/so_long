/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:29:35 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/05 17:46:57 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		++size;
	return (size);
}

/*int main(int argc, char *argv[]) 
{
	if (argc == 1)
	{
		return (0);
	}
	size_t length = ft_strlen(argv[1]);
	printf("Length of the string is: %zu\n", length);
	return (0);
}*/
