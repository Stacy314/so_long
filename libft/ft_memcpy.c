/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:07:31 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/08 13:07:51 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_cpy;
	unsigned char	*dst_cpy;

	if (dst == 0 && src == 0)
		return (NULL);
	src_cpy = (unsigned char *)src;
	dst_cpy = (unsigned char *)dst;
	i = 0;
	while (i++ < n)
		*(dst_cpy++) = *(src_cpy++);
	return (dst);
}

/*int main()
{
    // Define source and destination arrays
    char src[] = "Hello, world!";
    char dst[20];
    // Copy 13 bytes from src to dst
    ft_memcpy(dst, src, 13);
    // Null-terminate the destination string for printing
    dst[13] = '\0';
    // Print the copied string
    printf("Copied string: %s\n", dst);
    return 0;
}*/
