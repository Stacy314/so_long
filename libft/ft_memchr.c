/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:05:46 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/08 13:06:26 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_chr;
	unsigned char	c_chr;

	s_chr = (unsigned char *)s;
	c_chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_chr[i] == c_chr)
			return (s_chr + i);
		i++;
	}
	return (0);
}

/*int main() {
    const char str[] = "Hello, world!";
    char *result_std;
    char *result_ft;
    int character_to_find = 'o';
    size_t n = strlen(str);

    // Using the standard memchr function
    result_std = memchr(str, character_to_find, n);
    if (result_std != NULL)
        printf("memchr found '%c' at %ld.\n", character_to_find, 
        result_std - str);
    else
        printf("memchr did not find '%c'.\n", character_to_find);

    // Using your ft_memchr function
    result_ft = ft_memchr(str, character_to_find, n);
    if (result_ft != NULL)
        printf("ft_memchr found '%c' at %ld.\n", character_to_find, 
        result_ft - str);
    else
        printf("ft_memchr did not find '%c'.\n", character_to_find);

    return 0;
}*/
