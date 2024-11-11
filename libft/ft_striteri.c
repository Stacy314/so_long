/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:56:09 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/19 19:56:11 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == 0 && f == 0)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	ft_tolower_wrapper(unsigned int i, char *c)
{
	*c = (char)ft_tolower(*c);
}

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int main()
{
    char str[] = "Hello, world!";
    printf("Original string: %s\n", str);
    ft_striteri(str, ft_tolower_wrapper);
    printf("Modified string: %s\n", str);
    return 0;
}*/
