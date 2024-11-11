/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:19:07 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/08 16:47:57 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	fill(int i, int n, char *str)
{
	while (n != 0)
	{
		i--;
		str[i] = (char)(((n % 10) * (2 * (n > 0) - 1)) + '0');
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		num;
	int		i;
	char	*str;

	num = n;
	i = count(n);
	if (n < 0)
		i++;
	str = (char *)ft_calloc(sizeof(char) * (i + 1), 1);
	if (!str)
		return (0);
	str[i] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	fill(i, n, str);
	if (num < 0)
		str[0] = '-';
	return (str);
}
/*int main()
{
	printf("%s\n", ft_itoa(-342342));
	
	return (0);
}*/
