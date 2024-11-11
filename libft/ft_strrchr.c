/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:52:08 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/05 21:52:10 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

/*int main(void)
{
    const char *str = "Hello, World!";
    int char_find = 'W'; 

    char *result = ft_strrchr(str, char_find);

    if (result != NULL)
        printf("Character '%c' found: %ld\n", char_find, result - str);
    else
        printf("Character '%c' not found in the string.\n", char_find);
   return 0;
}*/
