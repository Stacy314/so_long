/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:14:40 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/08 16:49:17 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	char	*str;

	if (s == 0)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len || *s == '\0')
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)ft_calloc(sizeof(*s) * (len + 1), 1);
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

/*int main(void)
{
    char *s = "Hello, World!";
    char *substr = ft_substr(s, 7, 5); // Starting from index 7, length 5

    if (substr != NULL)
    {
        printf("Substring: %s\n", substr);
        free(substr);
    }
    else
    {
        printf("Substring is NULL\n");
    }

    return 0;
}*/
