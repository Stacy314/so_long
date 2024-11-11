/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:43:18 by apechkov          #+#    #+#             */
/*   Updated: 2024/04/05 16:43:20 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
/*int main() {
    char test_char;
    printf("Enter a character: ");
    scanf("%c", &test_char);

    if (ft_isalnum(test_char))
        printf("%c is an alpha.\n", test_char);
    else
        printf("%c is not an alpha.\n", test_char);

    return 0;
}*/
