/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:55:38 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/08 16:49:01 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*des;

	if (s == 0 || f == 0)
		return (NULL);
	i = 0;
	des = (char *)ft_calloc((ft_strlen(s) + 1) * sizeof(char), 1);
	if (des == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		des[i] = f(i, (char)s[i]);
		i++;
	}
	des[i] = '\0';
	return (des);
}

/*int	ft_tolower_wrapper(unsigned int i, char c)
{
	return ft_tolower(c);
}

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int main()
{
    char *modified_str;
    char str[] = "Hello, world!";
    printf("Original string: %s\n", str);
    modified_str = ft_strmapi(str, ft_tolower_wrapper);
    printf("Modified string: %s\n", modified_str);
    free(modified_str);
    return 0;
}*/
