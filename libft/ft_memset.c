/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:09:14 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/08 13:09:30 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*s_set;
	char		c_set;

	i = 0;
	s_set = (char *)s;
	c_set = (char)c;
	while (i < n)
		s_set[i++] = c_set;
	return (s);
}

/*int main() 
{
    // Example usage of ft_memset
    char str[20] = "sdfsdfsffhgjsrodi"; 

    // Using ft_memset to set the first 10 characters of str to 'A'
    ft_memset(str, 'A', 10);

    // Printing the modified string
    printf("Modified string: %s\n", str);

    return 0;
}*/
