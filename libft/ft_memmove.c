/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:08:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/08 13:09:02 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*last_d;
	unsigned char	*last_s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (NULL);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		last_s = s + (len - 1);
		last_d = d + (len - 1);
		while (len--)
			*last_d-- = *last_s--;
	}
	return (dst);
}

/*int	main(void)
{
 	char src[15] = "lorem ipsum";
 	char dst[20] = "dolor sit amet";
 	size_t len = 3;

 	printf("src: %s [ %p ]\n", src, &src);
 	printf("dst: %s [ %p ]\n", dst, &dst);
 	printf("-> dst: %s\n", ft_memmove(src, dst, len));
}*/
