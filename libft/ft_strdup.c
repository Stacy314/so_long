/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:51:52 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/08 17:16:47 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i])
		i++;
	dup = (char *)ft_calloc(i + 1, 1);
	if (dup == 0)
		return (NULL);
	while (i >= 0)
	{
		dup[i] = s[i];
		i--;
	}
	return (dup);
}

/*int main() {
    char src[] = "Hello, world!";
    char *duplicate = ft_strdup(src);

    if (duplicate != NULL) 
    {
        printf("Original string: %s\n", src);
        printf("Duplicate string: %s\n", duplicate);
        free(duplicate);
    } 
    else 
        printf("Memory allocation failed.\n");
    return 0;
}*/
