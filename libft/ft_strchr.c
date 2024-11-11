/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:13:24 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/02 13:48:54 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i])
			return (0);
		i++;
	}
	return ((char *)s + i);
}

char	*ft_strchr1(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

/*int main(void)
{
    const char *str = "teste";
    int char_find = 'e'; 

    char *result = strchr(str, char_find);

    if (result != NULL)
        printf("Character '%c' found: %ld\n", char_find, result - str);
    else
        printf("Character '%c' not found.\n", char_find);
   return 0;
}*/
