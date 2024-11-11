/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:46:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/08 16:57:06 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	res = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char), 1);
	if (res == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

/*int	main(void)
{
    char *s1 = "Hello, ";
    char *s2 = "world!";
    char *result = ft_strjoin(s1, s2);

    if (result != NULL)
    {
        printf("Concatenated string: %s\n", result);
        free(result);
    }
    else
        printf("Memory allocation failed\n");
    return 0;
}*/
