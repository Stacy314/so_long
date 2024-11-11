/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:44:51 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/02 16:45:01 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*buff;

	i = 0;
	buff = (unsigned char *)s;
	while (i < n)
		buff[i++] = 0;
}
/*int main()
{
    char str[12] = "Hello World";
    printf("Before bzero: %s\n", str);

    ft_bzero(str, 1);

    printf("After bzero: %s\n", str);

    return 0;
}*/
