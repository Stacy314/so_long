/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:56:25 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/02 15:56:35 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	if (!dst && src && !size)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	while (dst[j])
		j++;
	dstlen = j;
	srclen = ft_strlen(src);
	if (size == 0 || size <= dstlen)
		return (srclen + size);
	while (src[i] && i < size - dstlen - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dstlen + srclen);
}

/*int	main(void)
{
	char src[] = "World";
	char *dest = NULL;
	printf("%zu\n", ft_strlcat(dest, src, 0));
	printf("%s\n", dest);
	return (0);
}*/
