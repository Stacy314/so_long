/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:00:40 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/19 20:22:50 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && len > i)
	{
		n = i;
		j = 0;
		while (big[n] == little[j] && n < len && little[j] != '\0')
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
			n++;
		}
		i++;
	}
	return (NULL);
}

/*int main(void)
{
    const char *big = "Hello, world!";
    const char *little = "world";
    size_t len = 13;

    char *result = ft_strnstr(big, little, len);
    if (result != NULL)
        printf("'%s' found at index: %ld\n", little, result - big);
    else
        printf("'%s' not found\n", little);
    return 0;
}*/
