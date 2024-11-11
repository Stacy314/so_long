/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:07:02 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/08 13:07:19 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cmp;
	unsigned char	*s2_cmp;

	s1_cmp = (unsigned char *)s1;
	s2_cmp = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_cmp[i] != s2_cmp[i])
			return (s1_cmp[i] - s2_cmp[i]);
		i++;
	}
	return (0);
}

/*int main() 
{
    // Define two memory blocks to compare
    char block1[] = "Hello";
    char block2[] = "Hello";

    // Compare the first 5 characters of the two blocks
    int result = ft_memcmp(block1, block2, 5);

    // Print the result
    if (result == 0)
        printf("The first 5 characters of block1 and block2 are identical.\n");
    else if (result < 0)
        printf("The first 5 characters of block1 before block2.\n");
    else
        printf("The first 5 characters of block1 after block2.\n");
    return 0;
}*/
