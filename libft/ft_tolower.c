/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:25:35 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/05 18:28:46 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/*int main(int argc, char **argv)
{
	int	i;
	int	e;
	
	if (argc == 1)
	{
		return (0);
	}
	i = 0;
	e = 1;
	while (argc-- > 1)
	{
		while (argv[e][i] != '\0')
		{
			printf("%c\n", ft_tolower(argv[e][i]));
			i++;
		}
		i = 0;
		e++;
	}
	return(0);
}*/
